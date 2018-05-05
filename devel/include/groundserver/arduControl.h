// Generated by gencpp from file groundserver/arduControl.msg
// DO NOT EDIT!


#ifndef GROUNDSERVER_MESSAGE_ARDUCONTROL_H
#define GROUNDSERVER_MESSAGE_ARDUCONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace groundserver
{
template <class ContainerAllocator>
struct arduControl_
{
  typedef arduControl_<ContainerAllocator> Type;

  arduControl_()
    : arduYaw(0.0)
    , arduThrottle(0.0)
    , arduPitch(0.0)
    , arduRoll(0.0)
    , arduArmGripOn(0)
    , arduArmGripOff(0)
    , arduArmRoll(0)
    , arduLedOnOff(0)  {
    }
  arduControl_(const ContainerAllocator& _alloc)
    : arduYaw(0.0)
    , arduThrottle(0.0)
    , arduPitch(0.0)
    , arduRoll(0.0)
    , arduArmGripOn(0)
    , arduArmGripOff(0)
    , arduArmRoll(0)
    , arduLedOnOff(0)  {
  (void)_alloc;
    }



   typedef float _arduYaw_type;
  _arduYaw_type arduYaw;

   typedef float _arduThrottle_type;
  _arduThrottle_type arduThrottle;

   typedef float _arduPitch_type;
  _arduPitch_type arduPitch;

   typedef float _arduRoll_type;
  _arduRoll_type arduRoll;

   typedef int32_t _arduArmGripOn_type;
  _arduArmGripOn_type arduArmGripOn;

   typedef int32_t _arduArmGripOff_type;
  _arduArmGripOff_type arduArmGripOff;

   typedef int32_t _arduArmRoll_type;
  _arduArmRoll_type arduArmRoll;

   typedef int32_t _arduLedOnOff_type;
  _arduLedOnOff_type arduLedOnOff;




  typedef boost::shared_ptr< ::groundserver::arduControl_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::groundserver::arduControl_<ContainerAllocator> const> ConstPtr;

}; // struct arduControl_

typedef ::groundserver::arduControl_<std::allocator<void> > arduControl;

typedef boost::shared_ptr< ::groundserver::arduControl > arduControlPtr;
typedef boost::shared_ptr< ::groundserver::arduControl const> arduControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::groundserver::arduControl_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::groundserver::arduControl_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace groundserver

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geographic_msgs': ['/opt/ros/kinetic/share/geographic_msgs/cmake/../msg'], 'groundserver': ['/home/mfikih15/Documents/kapalTenggelam/serverGabut/src/groundserver/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'mavros_msgs': ['/opt/ros/kinetic/share/mavros_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'uuid_msgs': ['/opt/ros/kinetic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::groundserver::arduControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::groundserver::arduControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::groundserver::arduControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::groundserver::arduControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::groundserver::arduControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::groundserver::arduControl_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::groundserver::arduControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8be09c0c14bfbf4e4fcbd8778a348742";
  }

  static const char* value(const ::groundserver::arduControl_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8be09c0c14bfbf4eULL;
  static const uint64_t static_value2 = 0x4fcbd8778a348742ULL;
};

template<class ContainerAllocator>
struct DataType< ::groundserver::arduControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "groundserver/arduControl";
  }

  static const char* value(const ::groundserver::arduControl_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::groundserver::arduControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 arduYaw \n\
float32 arduThrottle\n\
float32 arduPitch\n\
float32 arduRoll\n\
int32 arduArmGripOn\n\
int32 arduArmGripOff\n\
int32 arduArmRoll\n\
int32 arduLedOnOff\n\
";
  }

  static const char* value(const ::groundserver::arduControl_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::groundserver::arduControl_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.arduYaw);
      stream.next(m.arduThrottle);
      stream.next(m.arduPitch);
      stream.next(m.arduRoll);
      stream.next(m.arduArmGripOn);
      stream.next(m.arduArmGripOff);
      stream.next(m.arduArmRoll);
      stream.next(m.arduLedOnOff);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct arduControl_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::groundserver::arduControl_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::groundserver::arduControl_<ContainerAllocator>& v)
  {
    s << indent << "arduYaw: ";
    Printer<float>::stream(s, indent + "  ", v.arduYaw);
    s << indent << "arduThrottle: ";
    Printer<float>::stream(s, indent + "  ", v.arduThrottle);
    s << indent << "arduPitch: ";
    Printer<float>::stream(s, indent + "  ", v.arduPitch);
    s << indent << "arduRoll: ";
    Printer<float>::stream(s, indent + "  ", v.arduRoll);
    s << indent << "arduArmGripOn: ";
    Printer<int32_t>::stream(s, indent + "  ", v.arduArmGripOn);
    s << indent << "arduArmGripOff: ";
    Printer<int32_t>::stream(s, indent + "  ", v.arduArmGripOff);
    s << indent << "arduArmRoll: ";
    Printer<int32_t>::stream(s, indent + "  ", v.arduArmRoll);
    s << indent << "arduLedOnOff: ";
    Printer<int32_t>::stream(s, indent + "  ", v.arduLedOnOff);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GROUNDSERVER_MESSAGE_ARDUCONTROL_H