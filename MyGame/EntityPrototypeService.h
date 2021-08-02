/*
 * My Game
 * 
 * Copyright (c) 2021 Jane Doe. All rights reserved.
 */

#pragma once

// AST-Utilities includes
#include <AstuServices.h>
#include <AstuECS.h>

class EntityPrototypeService : public astu::BaseService
{
public:

	// Constructor.
	EntityPrototypeService(bool debug = false);

private:
  // Whether debug mode is activated.
  bool debug;

  // Inherited via BaseService
  virtual void OnStartup() override;
  virtual void OnShutdown() override;

  std::shared_ptr<astu::Entity> CreateBoundary(float w, float h);
  std::shared_ptr<astu::Entity> CreateTestEntity();

};