/*
 * MyGame
 * 
 * Copyright (c) 2021 Jane Doe. All rights reserved.
 */

// Local includes
#include "EntityPrototypeService.h"
#include "Constants.h"

// AST-Utilities includes
#include <AstuSuite2D.h>

using namespace astu2d;
using namespace astu;
using namespace std;

EntityPrototypeService::EntityPrototypeService(bool debug)
  : BaseService("Entity Prototype Service")
  , debug(debug)
{
	// Intentionally left empty. 
}

void EntityPrototypeService::OnStartup()
{
	// Create and register entity prototypes.
	auto &entityFactory = ASTU_SERVICE(EntityFactoryService);

  // Register boundary entity prototypes.
  entityFactory.RegisterPrototype("HBoundary", CreateBoundary(VIEW_WIDTH, BOUNDARY_THICKNESS));
  entityFactory.RegisterPrototype("VBoundary", CreateBoundary(BOUNDARY_THICKNESS, VIEW_HEIGHT));

  // TODO register entity prototypes.
  entityFactory.RegisterPrototype("Test", CreateTestEntity());
}

void EntityPrototypeService::OnShutdown()
{
  // Cleanup.
  ASTU_SERVICE(EntityFactoryService).DeregisterAllPrototypes();
}

shared_ptr<Entity> EntityPrototypeService::CreateTestEntity()
{
  auto entity = make_shared<Entity>();
  entity->AddComponent(make_shared<CPose>(0.0f, 0.0f));

    entity->AddComponent(make_shared<CScene>(PolylineBuilder()
        .Color(TEST_ENTITY_COLOR)
        .VertexBuffer(ShapeGenerator().GenSquare(TEST_ENTITY_SIZE))
        .Build()));

  entity->AddComponent(CBodyBuilder()
      .Type(CBody::Type::Dynamic)
      .Build());

  entity->AddComponent(CPolygonColliderBuilder()
      .Polygon(ShapeGenerator().GenSquare(TEST_ENTITY_SIZE))
      .Friction(GENERAL_FRICTION)
      .Restitution(GENERAL_RESTITUTION)
      .Build());

  return entity;  
}

shared_ptr<Entity> EntityPrototypeService::CreateBoundary(float w, float h)
{
  auto entity = make_shared<Entity>();
  entity->AddComponent(make_shared<CPose>());

  if (debug) {
      entity->AddComponent(make_shared<CScene>(PolylineBuilder()
          .Color(BOUNDARY_COLOR)
          .VertexBuffer(ShapeGenerator().GenRectangle(w, h))
          .Build()));
  }

  entity->AddComponent(CBodyBuilder()
      .Type(CBody::Type::Static)
      .Build());

  entity->AddComponent(CPolygonColliderBuilder()
      .Polygon(ShapeGenerator().GenRectangle(w, h))
      .Friction(GENERAL_FRICTION)
      .Restitution(GENERAL_RESTITUTION)
      .Build());

  return entity;
}