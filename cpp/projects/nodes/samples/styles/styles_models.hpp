#pragma once

#include <QtCore/QObject>

#include "nodes/NodeData.hpp"
#include "nodes/NodeDataModel.hpp"

#include <memory>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class StyleMyNodeData : public NodeData
{
public:

  NodeDataType
  type() const override
  { return NodeDataType {"MyNodeData", "My Node Data"}; }
};

//------------------------------------------------------------------------------

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class StyleMyDataModel : public NodeDataModel
{
  Q_OBJECT

public:

  virtual
  ~StyleMyDataModel() {}

public:

  QString
  caption() const override
  {
    return QString("My Data Model");
  }

  QString
  name() const override
  {
    return QString("MyDataModel");
  }

public:

  QJsonObject
  save() const override
  {
    QJsonObject modelJson;

    modelJson["name"] = name();

    return modelJson;
  }

public:

  unsigned int
  nPorts(PortType) const override
  {
    return 3;
  }

  NodeDataType
  dataType(PortType, PortIndex) const override
  {
    return StyleMyNodeData().type();
  }

  std::shared_ptr<NodeData>
  outData(PortIndex) override
  {
    return std::make_shared<StyleMyNodeData>();
  }

  void
  setInData(std::shared_ptr<NodeData>, int) override
  {
    //
  }

  QWidget *
  embeddedWidget() override { return nullptr; }
};
