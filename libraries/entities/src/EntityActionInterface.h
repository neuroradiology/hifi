//
//  EntityActionInterface.h
//  libraries/entities/src
//
//  Created by Seth Alves on 2015-6-2
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef hifi_EntityActionInterface_h
#define hifi_EntityActionInterface_h

#include <QUuid>

class EntitySimulation;

enum EntityActionType {
    // keep these synchronized with actionTypeFromString and actionTypeToString
    ACTION_TYPE_NONE,
    ACTION_TYPE_PULL_TO_POINT
};


class EntityActionInterface {
public:
    EntityActionInterface() { }
    virtual ~EntityActionInterface() { }
    virtual const QUuid& getID() const = 0;
    virtual void removeFromSimulation(EntitySimulation* simulation) const = 0;
    virtual const EntityItemPointer& getOwnerEntity() const = 0;
    virtual void setOwnerEntity(const EntityItemPointer ownerEntity) = 0;
    virtual bool updateArguments(QVariantMap arguments) = 0;
    // virtual QByteArray serialize() = 0;
    // static EntityActionPointer deserialize(EntityItemPointer ownerEntity, QByteArray data);

    static EntityActionType actionTypeFromString(QString actionTypeString);
    static QString actionTypeToString(EntityActionType actionType);

protected:

    static glm::vec3 extractVec3Argument(QString objectName, QVariantMap arguments, QString argumentName, bool& ok);
    static float extractFloatArgument(QString objectName, QVariantMap arguments, QString argumentName, bool& ok);
};

typedef std::shared_ptr<EntityActionInterface> EntityActionPointer;

#endif // hifi_EntityActionInterface_h