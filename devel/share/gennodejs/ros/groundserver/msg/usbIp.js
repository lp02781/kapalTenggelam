// Auto-generated. Do not edit!

// (in-package groundserver.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class usbIp {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.throttle = null;
      this.steering = null;
      this.servoGrip = null;
      this.altitude = null;
    }
    else {
      if (initObj.hasOwnProperty('throttle')) {
        this.throttle = initObj.throttle
      }
      else {
        this.throttle = 0.0;
      }
      if (initObj.hasOwnProperty('steering')) {
        this.steering = initObj.steering
      }
      else {
        this.steering = 0.0;
      }
      if (initObj.hasOwnProperty('servoGrip')) {
        this.servoGrip = initObj.servoGrip
      }
      else {
        this.servoGrip = 0.0;
      }
      if (initObj.hasOwnProperty('altitude')) {
        this.altitude = initObj.altitude
      }
      else {
        this.altitude = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type usbIp
    // Serialize message field [throttle]
    bufferOffset = _serializer.float32(obj.throttle, buffer, bufferOffset);
    // Serialize message field [steering]
    bufferOffset = _serializer.float32(obj.steering, buffer, bufferOffset);
    // Serialize message field [servoGrip]
    bufferOffset = _serializer.float32(obj.servoGrip, buffer, bufferOffset);
    // Serialize message field [altitude]
    bufferOffset = _serializer.float32(obj.altitude, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type usbIp
    let len;
    let data = new usbIp(null);
    // Deserialize message field [throttle]
    data.throttle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [steering]
    data.steering = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [servoGrip]
    data.servoGrip = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [altitude]
    data.altitude = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'groundserver/usbIp';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5a9b5f9885099077c58386bfdab1c9a0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 throttle
    float32 steering
    float32 servoGrip
    float32 altitude
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new usbIp(null);
    if (msg.throttle !== undefined) {
      resolved.throttle = msg.throttle;
    }
    else {
      resolved.throttle = 0.0
    }

    if (msg.steering !== undefined) {
      resolved.steering = msg.steering;
    }
    else {
      resolved.steering = 0.0
    }

    if (msg.servoGrip !== undefined) {
      resolved.servoGrip = msg.servoGrip;
    }
    else {
      resolved.servoGrip = 0.0
    }

    if (msg.altitude !== undefined) {
      resolved.altitude = msg.altitude;
    }
    else {
      resolved.altitude = 0.0
    }

    return resolved;
    }
};

module.exports = usbIp;
