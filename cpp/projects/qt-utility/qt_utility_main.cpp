
/*******************************************************************************
** Toolbox-qt-utility                                                         **
** MIT License                                                                **
** Copyright (c) [2018] [Florian Lance]                                       **
**                                                                            **
** Permission is hereby granted, free of charge, to any person obtaining a    **
** copy of this software and associated documentation files (the "Software"), **
** to deal in the Software without restriction, including without limitation  **
** the rights to use, copy, modify, merge, publish, distribute, sublicense,   **
** and/or sell copies of the Software, and to permit persons to whom the      **
** Software is furnished to do so, subject to the following conditions:       **
**                                                                            **
** The above copyright notice and this permission notice shall be included in **
** all copies or substantial portions of the Software.                        **
**                                                                            **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    **
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    **
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        **
** DEALINGS IN THE SOFTWARE.                                                  **
**                                                                            **
********************************************************************************/
#include <iostream>
#include <any>

// Qt
#include <QTextStream>
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QHostInfo>

#include "qt_logger.hpp"


using namespace tool;

void display_lines();

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    QLocale::setDefault(QLocale::c());    
//    display_lines();

    tool::QtLogger::init("","");
    QApplication::connect(QtLogger::get(), &QtLogger::message_signal,  [&](QString message){
        qDebug() << "M " << message;
//        m_ui->teLogs->insertHtml(message % QSL("<br>"));
//        QTextCursor cursor = m_ui->teLogs->textCursor();
//        cursor.movePosition(QTextCursor::End);
//        m_ui->teLogs->setTextCursor(cursor);

    });


    QtLogger::message(QSL("Qt-utility"));

    qDebug() << "test";

    return a.exec();
}


size_t countLines(QString path){
    QFile f(path);
    size_t cnt = 0;

    if(f.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream read(&f);
        while(!read.atEnd()){
            read.readLine();
            cnt++;
        }
    }
    f.close();
    return cnt;
}

int countLines2(QString path){
    QFile f(path);
    int cnt = 0;

    if(f.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream read(&f);
        QString line;
        bool comment = false;
        while(!read.atEnd()){
            line = read.readLine();
            line = line.simplified();
            line.replace(" ","");
            if(line.size() >0){
                if(line.leftRef(2) != "//"){
                    if(line.contains("/*"))
                        comment = true;
                    if(line.contains("*/"))
                        comment = false;
                    if(!comment)
                        cnt++;
                }
            }
        }
    }
    f.close();
    return cnt;
}

struct DirContent{
    size_t cpp =0;
    size_t c = 0;
    size_t h = 0;
    size_t hpp = 0;
    size_t cs = 0;
    size_t pro = 0;
};


size_t parseDir(QString path){
    size_t cnt = 0;
    QDir dir(path);
    QStringList dirs = dir.entryList(QDir::AllDirs |QDir::NoDotAndDotDot);
    QStringList file = dir.entryList(QDir::Files);
    for(QString dir : dirs){
            cnt += parseDir(path + "/"+dir);
    }

    for(QString s : file){

        auto last = s.splitRef('.').last();

        if(last == "hpp" || last == "cpp" || last == "h" || last == "pri" || last == "pro" || last == "config" || last == "cs"){
            size_t c = countLines(path + "/"+s);
            qDebug() << (path + "/"+s) << " -> " << c;
            cnt += c;
        }
    }

    return cnt;
}

void display_lines(){

    int count = 0;
    qDebug() << "Lines in full projects "<< count;
    QString baseDir = "E:/DEV/EPFL/exvr/cpp/toolbox/";

    std::vector<QString> paths;
    paths.emplace_back(baseDir + "base");
    paths.emplace_back(baseDir + "nodes");
    paths.emplace_back(baseDir + "3d-engine");
    paths.emplace_back(baseDir + "arduino");
    paths.emplace_back(baseDir + "mouvement");
    paths.emplace_back(baseDir + "prenom");
    paths.emplace_back(baseDir + "opengl-utility");
    paths.emplace_back(baseDir + "qt-utility");
    paths.emplace_back(baseDir + "shading-cookbook");
    paths.emplace_back(baseDir + "vulkan");

    baseDir = "E:/DEV/EPFL/exvr/cpp/exvr/";
    paths.emplace_back(baseDir + "cameras-synchronizer");
    paths.emplace_back(baseDir + "components");
    paths.emplace_back(baseDir + "designer");
    paths.emplace_back(baseDir + "export");
    paths.emplace_back(baseDir + "scaner-base");
    paths.emplace_back(baseDir + "scaner-component");
    paths.emplace_back(baseDir + "scaner-grabber");
    paths.emplace_back(baseDir + "scaner-manager");
    paths.emplace_back(baseDir + "sonceboz-controller");

    baseDir = "E:/DEV/EPFL/exvr/unity/exvr-exp/Assets/_scripts";
    paths.emplace_back(baseDir);

    size_t totalCount = 0;
    for(const auto &path : paths){
        size_t count = parseDir(path);
        totalCount += count;
        qDebug() << "Lines in path: " << path;
        qDebug() << "   -> " << count;
    }
    qDebug() << "TOTAL: " << totalCount;
}


