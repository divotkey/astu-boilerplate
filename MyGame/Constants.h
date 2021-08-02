/*
 * My Game
 * 
 * Copyright (c) 2021 Jane Doe. All rights reserved.
 */

#pragma once

// AST Utilities includes
#include <AstuGraphics.h>
#include <AstuInput.h>

/////////////////////////////////////////////////
/////// General constants
/////////////////////////////////////////////////
#define VIEW_WIDTH                  16.0f
#define VIEW_HEIGHT                 9.0f
#define BOUNDARY_THICKNESS          0.5f
#define BACKGROUND_COLOR            astu::RalColors::TrafficBlack
#define BOUNDARY_COLOR              astu::RalColors::TrafficGreen

/////////////////////////////////////////////////
/////// Physics constants
/////////////////////////////////////////////////
#define GRAVITY                     astu::Vector2f(0, 9.81f)
#define GENERAL_RESTITUTION         0.5f
#define GENERAL_FRICTION            0.2f

/////////////////////////////////////////////////
/////// Constants for game entities
/////////////////////////////////////////////////
#define TEST_ENTITY_SIZE            1.0f
#define TEST_ENTITY_COLOR           RalColors::TrafficOrange