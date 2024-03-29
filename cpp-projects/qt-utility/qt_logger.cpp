
/*******************************************************************************
** exvr-designer                                                              **
** No license (to be defined)                                                 **
** Copyright (c) [2018] [Florian Lance][EPFL-LNCO]                            **
********************************************************************************/

#include "qt_logger.hpp"

// std
#include <mutex>

// Qt
#include <QDir>
#include <QFile>
#include <QApplication>
#include <QDateTime>
#include <QHostInfo>
#include <QString>

// base
//#include "utility/logger.hpp"
#include "utility/time.hpp"

// qt-utility
#include "qt_str.hpp"

using namespace tool;


struct QtLogger::Impl{

    static inline std::mutex locker;
    static inline std::unique_ptr<QtLogger> logger = nullptr;
    static inline std::unique_ptr<QFile> file = nullptr;
    static inline std::unique_ptr<QTextStream> out = nullptr;

    static inline std::chrono::nanoseconds epochStart;

    static const inline QString startHtmlBalise           = QSL("<p>");
    static const inline QString startTimestampHtmlBalise  = QSL("<p> [");
    static const inline QString midTimestampHtmlBalise    = QSL("] ");
    static const inline QString endHtmlBalise             = QSL("</font></p>\n");

    static const inline QString htmlDarkBlueColorBalise   = QSL("<font color=\"DarkBlue\">");
    static const inline QString htmlDarkOrangeColorBalise = QSL("<font color=\"Orange\">");
    static const inline QString htmlDarkRedColorBalise    = QSL("<font color=\"DarkRed\">");
    static const inline QString htmlDarkBlackColorBalise  = QSL("<font color=\"Black\">");

    Impl(){
    }
};

QtLogger::QtLogger() : m_p(std::make_unique<Impl>()){
}

QtLogger *QtLogger::get(){
    if(QtLogger::Impl::logger != nullptr){
        return QtLogger::Impl::logger.get();
    }
    return nullptr;
}

QString QtLogger::to_html_line(QtLogger::MessageType type, QStringView text, bool addTimestamp){

    QStringView colorCode;
    switch (type) {
    case QtLogger::MessageType::normal:
        colorCode = QtLogger::Impl::htmlDarkBlueColorBalise;
        break;
    case QtLogger::MessageType::warning:
        colorCode = QtLogger::Impl::htmlDarkOrangeColorBalise;
        break;
    case QtLogger::MessageType::error:
        colorCode = QtLogger::Impl::htmlDarkRedColorBalise;
        break;
    case QtLogger::MessageType::unknow:
        colorCode = QtLogger::Impl::htmlDarkBlackColorBalise;
        break;
    }

    if(!addTimestamp){
        return QString("%1%2%3%4").arg(QtLogger::Impl::startHtmlBalise, colorCode, text, QtLogger::Impl::endHtmlBalise);
    }else{
        return QString("%1%2%3%4%5%6").arg(
            QtLogger::Impl::startTimestampHtmlBalise,
            QString::number(std::chrono::duration_cast<std::chrono::milliseconds>(nanoseconds_since_epoch() - QtLogger::Impl::epochStart).count()),
            QtLogger::Impl::midTimestampHtmlBalise,
            colorCode,
            text,
            QtLogger::Impl::endHtmlBalise
        );
    }
}

void QtLogger::insert_line_to_log_file(QtLogger::MessageType type, QStringView message){

    std::unique_lock<std::mutex> lock(QtLogger::Impl::locker);
    if(QtLogger::Impl::out){
        (*QtLogger::Impl::out) << to_html_line(type, message, true);
    }
}


void QtLogger::init(QString logDirectoryPath, QString logFileName){

    if(logDirectoryPath.length() == 0 || logFileName.length() == 0){
        logDirectoryPath = QApplication::applicationDirPath() % QSL("/logs");
        logFileName      = QSL("default_") % QHostInfo::localHostName() % QSL(".html");
    }

    QString logDirPath       = logDirectoryPath;
    QString logName          = logFileName;
    QString absoluteFilePath = logDirPath % "/" % logName;

    if(!QFile::exists(logDirPath)){
        QDir logDir(logDirPath);
        if(!logDir.mkdir(logDirPath)){
            qWarning() << "[QtLogger-ERROR] Cannot create logging directory path.\n";
            return;
        }
    }

    std::unique_lock<std::mutex> lock(QtLogger::Impl::locker);
    if(QtLogger::Impl::logger == nullptr){

//        if(QFile::exists(absoluteFilePath)){

//            int id = absoluteFilePath.lastIndexOf('.');
//            if(id == -1){
//                // error
//                return;
//            }

//            auto leftPart  = absoluteFilePath.left(id);
//            auto extension = absoluteFilePath.mid(id);
//            auto newFileName  = leftPart % QSL("_previous") % extension;

//            auto previousPath = absoluteFilePath;
//            previousPath.replace_filename(newFileName);

//            bool copyPrevious = true;
//            if(fs::exists(previousPath)){
//                if(!fs::remove(previousPath)){
//                    std::cerr << "[LOGGER-ERROR] Cannot remove previous log file.\n";
//                    copyPrevious = false;
//                }
//            }

//            if(copyPrevious){
//                fs::copy(absoluteFilePath, previousPath);
//            }
//        }

        // init log file
        QtLogger::Impl::epochStart = nanoseconds_since_epoch();
        QtLogger::Impl::logger     = std::make_unique<QtLogger>();
        QtLogger::Impl::file       = std::make_unique<QFile>(absoluteFilePath);

        if(!QtLogger::Impl::file->open(QFile::WriteOnly | QFile::Text)){
            qWarning() << "[QtLogger-ERROR] Cannot write to log file: " << absoluteFilePath;;
            return;
        }

        QtLogger::Impl::out = std::make_unique<QTextStream>(QtLogger::Impl::file.get());
    }
}

void QtLogger::clean(){

    std::unique_lock<std::mutex> lock(QtLogger::Impl::locker);
    if(QtLogger::Impl::file){
        QtLogger::Impl::file->close();
        QtLogger::Impl::file = nullptr;
        QtLogger::Impl::out  = nullptr;
    }
    QtLogger::Impl::logger = nullptr;
}

void QtLogger::message(const QString &message, bool triggersSignal, bool saveToFile){

    if(auto logger = QtLogger::get(); logger != nullptr){

        if(triggersSignal){
            emit QtLogger::Impl::logger->message_signal(
                to_html_line(MessageType::normal, message, false)
            );
        }

        if(saveToFile){
            insert_line_to_log_file(MessageType::normal, message);
        }
    }
}

void QtLogger::error(const QString &error, bool triggersSignal, bool saveToFile){

    if(auto logger = QtLogger::get(); logger != nullptr){

        if(triggersSignal){
            emit QtLogger::Impl::logger->error_signal(
                to_html_line(MessageType::error, error, false)
            );
        }

        if(saveToFile){
            insert_line_to_log_file(MessageType::error, error);
        }
    }
}

void QtLogger::warning(const QString &warning, bool triggersSignal, bool saveToFile){

    if(auto logger = QtLogger::get(); logger != nullptr){

        if(triggersSignal){
            emit QtLogger::Impl::logger->warning_signal(
                to_html_line(MessageType::warning, warning, false)
            );
        }

        if(saveToFile){
            insert_line_to_log_file(MessageType::warning, warning);
        }
    }
}

void QtLogger::status(const QString &status, int ms){
    if(auto logger = QtLogger::get(); logger != nullptr){
        emit QtLogger::Impl::logger->status_signal(status, ms);
    }
}

void QtLogger::progress(int state){
    if(auto logger = QtLogger::get(); logger != nullptr){
        emit QtLogger::Impl::logger->progress_signal(state);
    }
}

void QtLogger::unity_message(QStringView message, bool triggersSignal, bool saveToFile){

    if(auto logger = QtLogger::get(); logger != nullptr){

        if(triggersSignal){
            int idRichText = message.indexOf(QSL("|R|"));
            if(idRichText != -1){
                emit QtLogger::Impl::logger->unity_message_signal(message.chopped(idRichText));
            }else{
                emit QtLogger::Impl::logger->unity_message_signal(message);
            }
        }

        if(saveToFile){
            insert_line_to_log_file(MessageType::normal, message);
        }
    }
}

void QtLogger::unity_error(QStringView error, bool triggersSignal, bool saveToFile){

    if(auto logger = QtLogger::get(); logger != nullptr){

        if(triggersSignal){
//            int idRichText = error.indexOf(QSL("<font color="));
//            if(idRichText != -1){
//                emit QtLogger::Impl::logger->unity_error_signal(error.chopped(idRichText));
//            }else{
                emit QtLogger::Impl::logger->unity_error_signal(error);
//            }
        }

        if(saveToFile){
            insert_line_to_log_file(MessageType::error, error);
        }
    }
}

void QtLogger::unity_warning(QStringView warning, bool triggersSignal, bool saveToFile){

    if(auto logger = QtLogger::get(); logger != nullptr){

        if(triggersSignal){
//            int idRichText = warning.indexOf(QSL("<font color="));
//            if(idRichText != -1){
//                emit QtLogger::Impl::logger->unity_warning_signal(warning.chopped(idRichText));
//            }else{
                emit QtLogger::Impl::logger->unity_warning_signal(warning);
//            }
        }

        if(saveToFile){
            insert_line_to_log_file(MessageType::warning, warning);
        }
    }
}

void QtLogger::unity_unknow(QStringView unknow, bool triggersSignal, bool saveToFile){

    if(auto logger = QtLogger::get(); logger != nullptr){

        if(triggersSignal){
//            int idRichText = unknow.indexOf(QSL("<font color="));
//            if(idRichText != -1){
//                emit QtLogger::Impl::logger->unity_unknow_signal(unknow.chopped(idRichText));
//            }else{
                emit QtLogger::Impl::logger->unity_unknow_signal(unknow);
//            }
        }

        if(saveToFile){
            insert_line_to_log_file(MessageType::unknow, unknow);
        }
    }
}




#include "moc_qt_logger.cpp"
