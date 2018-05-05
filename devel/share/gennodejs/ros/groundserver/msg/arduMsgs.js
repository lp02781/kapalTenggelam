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

class arduMsgs {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.arduYaw = null;
      this.arduThrottle = null;
      this.arduPitch = null;
      this.arduRoll = null;
      this.arduArmGripOn = null;
      this.arduArmGripOff = null;
      this.arduArmRoll = null;
      this.arduLedOnOff = null;
    }
    else {
      if (initObj.hasOwnProperty('arduYaw')) {
        this.arduYaw = initObj.arduYaw
      }
      else {
        this.arduYaw = 0.0;
      }
      if (initObj.hasOwnProperty('arduThrottle')) {
        this.arduThrottle = initObj.arduThrottle
      }
      else {
        this.arduThrottle = 0.0;
      }
      if (initObj.hasOwnProperty('arduPitch')) {
        this.arduPitch = initObj.arduPitch
      }
      else {
        this.arduPitch = 0.0;
      }
      if (initObj.hasOwnProperty('arduRoll')) {
        this.arduRoll = initObj.arduRoll
      }
      else {
        this.arduRoll = 0.0;
      }
      if (initObj.hasOwnProperty('arduArmGripOn')) {
        this.arduArmGripOn = initObj.arduArmGripOn
      }
      else {
        this.arduArmGripOn = 0;
      }
      if (initObj.hasOwnProperty('arduArmGripOff')) {
        this.arduArmGripOff = initObj.arduArmGripOff
      }
      else {
        this.arduArmGripOff = 0;
      }
      if (initObj.hasOwnProperty('arduArmRoll')) {
        this.arduArmRoll = initObj.arduArmRoll
      }
      else {
        this.arduArmRoll = 0;
      }
      if (initObj.hasOwnProperty('arduLedOnOff')) {
        this.arduLedOnOff = initObj.arduLedOnOff
      }
      else {
        this.arduLedOnOff = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type arduMsgs
    // Serialize message field [arduYaw]
    bufferOffset = _serializer.float32(obj.arduYaw, buffer, bufferOffset);
    // Serialize message field [arduThrottle]
    bufferOffset = _serializer.float32(obj.arduThrottle, buffer, bufferOffset);
    // Serialize message field [arduPitch]
    bufferOffset = _serializer.float32(obj.arduPitch, buffer, bufferOffset);
    // Serialize message field [arduRoll]
    bufferOffset = _serializer.float32(obj.arduRoll, buffer, bufferOffset);
    // Serialize message field [arduArmGripOn]
    bufferOffset = _serializer.int32(obj.arduArmGripOn, buffer, bufferOffset);
    // Serialize message field [arduArmGripOff]
    bufferOffset = _serializer.int32(obj.arduArmGripOff, buffer, bufferOffset);
    // Serialize message field [arduArmRoll]
    bufferOffset = _serializer.int32(obj.arduArmRoll, buffer, bufferOffset);
    // Serialize message field [arduLedOnOff]
    bufferOffset = _serializer.int32(obj.arduLedOnOff, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type arduMsgs
    let len;
    let data = new arduMsgs(null);
    // Deserialize message field [arduYaw]
    data.arduYaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arduThrottle]
    data.arduThrottle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arduPitch]
    data.arduPitch = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arduRoll]
    data.arduRoll = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arduArmGripOn]
    data.arduArmGripOn = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [arduArmGripOff]
    data.arduArmGripOff = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [arduArmRoll]
    data.arduArmRoll = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [arduLedOnOff]
    data.arduLedOnOff = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'groundserver/arduMsgs';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8be09c0c14bfbf4e4fcbd8778a348742';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 arduYaw 
    float32 arduThrottle
    float32 arduPitch
    float32 arduRoll
    int32 arduArmGripOn
    int32 arduArmGripOff
    int32 arduArmRoll
    int32 arduLedOnOff
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new arduMsgs(null);
    if (msg.arduYaw !== undefined) {
      resolved.arduYaw = msg.arduYaw;
    }
    else {
      resolved.arduYaw = 0.0
    }

    if (msg.arduThrottle !== undefined) {
      resolved.arduThrottle = msg.arduThrottle;
    }
    else {
      resolved.arduThrottle = 0.0
    }

    if (msg.arduPitch !== undefined) {
      resolved.arduPitch = msg.arduPitch;
    }
    else {
      resolved.arduPitch = 0.0
    }

    if (msg.arduRoll !== undefined) {
      resolved.arduRoll = msg.arduRoll;
    }
    else {
      resolved.arduRoll = 0.0
    }

    if (msg.arduArmGripOn !== undefined) {
      resolved.arduArmGripOn = msg.arduArmGripOn;
    }
    else {
      resolved.arduArmGripOn = 0
    }

    if (msg.arduArmGripOff !== undefined) {
      resolved.arduArmGripOff = msg.arduArmGripOff;
    }
    else {
      resolved.arduArmGripOff = 0
    }

    if (msg.arduArmRoll !== undefined) {
      resolved.arduArmRoll = msg.arduArmRoll;
    }
    else {
      resolved.arduArmRoll = 0
    }

    if (msg.arduLedOnOff !== undefined) {
      resolved.arduLedOnOff = msg.arduLedOnOff;
    }
    else {
      resolved.arduLedOnOff = 0
    }

    return resolved;
    }
};

module.exports = arduMsgs;
