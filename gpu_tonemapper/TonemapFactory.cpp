/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "TonemapFactory.h"
#include <utils/Log.h>
#include "EGLImageWrapper.h"
#include "Tonemapper.h"
#include "engine.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------
Tonemapper *TonemapperFactory_GetInstance(int type, void *colorMap, int colorMapSize,
                                          void *lutXform, int lutXformSize)
//----------------------------------------------------------------------------------------------------------------------------------------------------------
{
  // initializes the engine - does nothing if already initialized
  engine_initialize();

  // build the tonemapper
  Tonemapper *tonemapper = Tonemapper::build(type, colorMap, colorMapSize, lutXform, lutXformSize);

  return tonemapper;
}

//------------------------------------------
void TonemapperFactory_Destroy()
//------------------------------------------
{
  // clear EGLImage mappings
  EGLImageWrapper::destroy();
  // shutdown the engine
  engine_shutdown();
}