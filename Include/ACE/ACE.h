/********************************************************************************
 *                                                                              *
 *          Copyright (C) 2017 Oleksandr Lynok. All Rights Reserved.            *
 *                                                                              *
 *                  This file is part of Advanced Crystal Engine.               *
 *                                                                              *
 *      Advanced Crystal Engine is licensed under GNU Lesser General Public     *
 *  License (LGPL), version 3.  See file "LICENSE.txt".                         *
 *                                                                              *
 ********************************************************************************/

#pragma once

/*
 *  Audio
 */
#include <ACE/Audio/AudioComponent.h>
#include <ACE/Audio/AudioContext.h>
#include <ACE/Audio/AudioDevice.h>
#include <ACE/Audio/AudioListener.h>
#include <ACE/Audio/AudioManager.h>
#include <ACE/Audio/AudioResource.h>
#include <ACE/Audio/AudioSource.h>
#include <ACE/Audio/AudioSourceState.h>

/*
 *  Base
 */
#include <ACE/Base/Containers/List.h>
#include <ACE/Base/Containers/Map.h>
#include <ACE/Base/Containers/Queue.h>
#include <ACE/Base/Containers/String.h>
#include <ACE/Base/Containers/Vector.h>

#include <ACE/Base/Misc/Assert.h>
#include <ACE/Base/Misc/Macro.h>
#include <ACE/Base/Misc/Mutex.h>
#include <ACE/Base/Misc/PlatformDetection.h>
#include <ACE/Base/Misc/SharedPointer.h>
#include <ACE/Base/Misc/Thread.h>
#include <ACE/Base/Misc/Types.h>
#include <ACE/Base/Misc/UniquePointer.h>

#include <ACE/Base/BaseHeader.h>
#include <ACE/Base/Initializable.h>
#include <ACE/Base/InitializationStatus.h>
#include <ACE/Base/Loadable.h>
#include <ACE/Base/LoadingStatus.h>
#include <ACE/Base/Manager.h>
#include <ACE/Base/Object.h>
#include <ACE/Base/Singleton.h>

/*
 *  Core
 */
#include <ACE/Core/Config/ConfigManager.h>
#include <ACE/Core/Config/IConfigParam.h>
#include <ACE/Core/Config/TConfigParam.h>
#include <ACE/Core/Config/TConfigParam.inl>

#include <ACE/Core/Logging/LoggingCategory.h>
#include <ACE/Core/Logging/LoggingLevel.h>
#include <ACE/Core/Logging/LoggingManager.h>

#include <ACE/Core/Profiling/ProfilingManager.h>

#include <ACE/Core/ObjectManager.h>

/*
 *  Event
 */
#include <ACE/Event/Event.h>
#include <ACE/Event/EventManager.h>
#include <ACE/Event/EventType.h>

/*
 *  Game
 */
#include <ACE/Game/GameComponent.h>
#include <ACE/Game/GameManager.h>
#include <ACE/Game/GameResource.h>
#include <ACE/Game/Scene.h>
#include <ACE/Game/SceneComponent.h>
#include <ACE/Game/SceneManager.h>
#include <ACE/Game/SceneObject.h>

/*
 *  Graphic
 */
#include <ACE/Graphic/Camera.h>
#include <ACE/Graphic/GraphicComponent.h>
#include <ACE/Graphic/GraphicContext.h>
#include <ACE/Graphic/GraphicManager.h>
#include <ACE/Graphic/GraphicResource.h>
#include <ACE/Graphic/Viewport.h>
#include <ACE/Graphic/Window.h>
#include <ACE/Graphic/WindowManager.h>

/*
 *  Math
 */
#include <ACE/Math/Matrix.h>
#include <ACE/Math/Misc.h>
#include <ACE/Math/Vector.h>

/*
 *  Network
 */
#include <ACE/Network/NetworkManager.h>

/*
 *  Physic
 */
#include <ACE/Physic/PhysicManager.h>

/*
 *  Resource
 */
#include <ACE/Resource/AudioResource.h>
#include <ACE/Resource/ModelResource.h>
#include <ACE/Resource/Resource.h>
#include <ACE/Resource/ResourceManager.h>
#include <ACE/Resource/ShaderResource.h>
#include <ACE/Resource/TextureResource.h>

/*
 *  Script
 */
#include <ACE/Script/ScriptManager.h>

#include <ACE/Application.h>
#include <ACE/PrecompiledHeader.h>
#include <ACE/Settings.h>
#include <ACE/SettingsBase.h>