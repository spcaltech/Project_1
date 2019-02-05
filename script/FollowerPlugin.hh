1 /*
2  * Copyright (C) 2016 Open Source Robotics Foundation
3  *
4  * Licensed under the Apache License, Version 2.0 (the "License");
5  * you may not use this file except in compliance with the License.
6  * You may obtain a copy of the License at
7  *
8  * http://www.apache.org/licenses/LICENSE-2.0
9  *
10  * Unless required by applicable law or agreed to in writing, software
11  * distributed under the License is distributed on an "AS IS" BASIS,
12  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
13  * See the License for the specific language governing permissions and
14  * limitations under the License.
15  *
16 */
17 
18 #ifndef GAZEBO_PLUGINS_FOLLOWERPLUGIN_HH_
19 #define GAZEBO_PLUGINS_FOLLOWERPLUGIN_HH_
20 
21 #include <memory>
22 #include <string>
23 
24 #include <sdf/sdf.hh>
25 
26 #include <gazebo/common/Plugin.hh>
27 #include <gazebo/physics/PhysicsTypes.hh>
28 
29 namespace gazebo
30 {
31  // Forward declare private class
32  struct FollowerPluginPrivate;
33 
38  class GAZEBO_VISIBLE FollowerPlugin : public ModelPlugin
39  {
41  public: FollowerPlugin();
42 
44  public: ~FollowerPlugin();
45 
46  // Documentation Inherited.
47  public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);
48 
49  // Documentation Inherited.
50  public: virtual void Init();
51 
52  // Documentation Unherited.
53  public: virtual void Reset();
54 
61  private: void OnNewDepthFrame(const float *_image,
62  const unsigned int _width, const unsigned int _height,
63  const unsigned int _depth, const std::string &_format);
64 
66  private: void OnUpdate();
67 
71  private: bool FindSensor(const physics::ModelPtr &_model);
72 
74  private: void FindJoints();
75 
77  private: void UpdateFollower();
78 
80  private: std::unique_ptr<FollowerPluginPrivate> dataPtr;
81  };
82 }
83 #endif