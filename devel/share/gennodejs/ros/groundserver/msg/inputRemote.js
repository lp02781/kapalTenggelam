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

class inputRemote {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.codeYaw = null;
      this.codeThrottle = null;
      this.codePitch = null;
      this.codeRoll = null;
      this.codeArmGripOn = null;
      this.codeArmGripOff = null;
      this.codeStabilizeMode = null;
      this.codeRemoteArmed = null;
    }
    else {
      if (initObj.hasOwnProperty('codeYaw')) {
        this.codeYaw = initObj.codeYaw
      }
      else {
        this.codeYaw = 0;
      }
      if (initObj.hasOwnProperty('codeThrottle')) {
        this.codeThrottle = initObj.codeThrottle
      }
      else {
        this.codeThrottle = 0;
      }
      if (initObj.hasOwnProperty('codePitch')) {
        this.codePitch = initObj.codePitch
      }
      else {
        this.codePitch = 0;
      }
      if (initObj.hasOwnProperty('codeRoll')) {
        this.codeRoll = initObj.codeRoll
      }
      else {
        this.codeRoll = 0;
      }
      if (initObj.hasOwnProperty('codeArmGripOn')) {
        this.codeArmGripOn = initObj.codeArmGripOn
      }
      else {
        this.codeArmGripOn = 0;
      }
      if (initObj.hasOwnProperty('codeArmGripOff')) {
        this.codeArmGripOff = initObj.codeArmGripOff
      }
      else {
        this.codeArmGripOff = 0;
      }
      if (initObj.hasOwnProperty('codeStabilizeMode')) {
        this.codeStabilizeMode = initObj.codeStabilizeMode
      }
      else {
        this.codeStabilizeMode = 0;
      }
      if (initObj.hasOwnProperty('codeRemoteArmed')) {
        this.codeRemoteArmed = initObj.codeRemoteArmed
      }
      else {
        this.codeRemoteArmed = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type inputRemote
    // Serialize message field [codeYaw]
    bufferOffset = _serializer.int8(obj.codeYaw, buffer, bufferOffset);
    // Serialize message field [codeThrottle]
    bufferOffset = _serializer.int8(obj.codeThrottle, buffer, bufferOffset);
    // Serialize message field [codePitch]
    bufferOffset = _serializer.int8(obj.codePitch, buffer, bufferOffset);
    // Serialize message field [codeRoll]
    bufferOffset = _serializer.int8(obj.codeRoll, buffer, bufferOffset);
    // Serialize message field [codeArmGripOn]
    bufferOffset = _serializer.int8(obj.codeArmGripOn, buffer, bufferOffset);
    // Serialize message field [codeArmGripOff]
    bufferOffset = _serializer.int8(obj.codeArmGripOff, buffer, bufferOffset);
    // Serialize message field [codeStabilizeMode]
    bufferOffset = _serializer.int8(obj.codeStabilizeMode, buffer, bufferOffset);
    // Serialize message field [codeRemoteArmed]
    bufferOffset = _serializer.int8(obj.codeRemoteArmed, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type inputRemote
    let len;
    let data = new inputRemote(null);
    // Deserialize message field [codeYaw]
    data.codeYaw = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [codeThrottle]
    data.codeThrottle = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [codePitch]
    data.codePitch = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [codeRoll]
    data.codeRoll = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [codeArmGripOn]
    data.codeArmGripOn = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [codeArmGripOff]
    data.codeArmGripOff = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [codeStabilizeMode]
    data.codeStabilizeMode = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [codeRemoteArmed]
    data.codeRemoteArmed = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'groundserver/inputRemote';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '60b79f3a2f7dab179828919f073b14bf';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 codeYaw 
    int8 codeThrottle
    int8 codePitch
    int8 codeRoll
    int8 codeArmGripOn
    int8 codeArmGripOff
    int8 codeStabilizeMode
    int8 codeRemoteArmed
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new inputRemote(null);
    if (msg.codeYaw !== undefined) {
      resolved.codeYaw = msg.codeYaw;
    }
    else {
      resolved.codeYaw = 0
    }

    if (msg.codeThrottle !== undefined) {
      resolved.codeThrottle = msg.codeThrottle;
    }
    else {
      resolved.codeThrottle = 0
    }

    if (msg.codePitch !== undefined) {
      resolved.codePitch = msg.codePitch;
    }
    else {
      resolved.codePitch = 0
    }

    if (msg.codeRoll !== undefined) {
      resolved.codeRoll = msg.codeRoll;
    }
    else {
      resolved.codeRoll = 0
    }

    if (msg.codeArmGripOn !== undefined) {
      resolved.codeArmGripOn = msg.codeArmGripOn;
    }
    else {
      resolved.codeArmGripOn = 0
    }

    if (msg.codeArmGripOff !== undefined) {
      resolved.codeArmGripOff = msg.codeArmGripOff;
    }
    else {
      resolved.codeArmGripOff = 0
    }

    if (msg.codeStabilizeMode !== undefined) {
      resolved.codeStabilizeMode = msg.codeStabilizeMode;
    }
    else {
      resolved.codeStabilizeMode = 0
    }

    if (msg.codeRemoteArmed !== undefined) {
      resolved.codeRemoteArmed = msg.codeRemoteArmed;
    }
    else {
      resolved.codeRemoteArmed = 0
    }

    return resolved;
    }
};

module.exports = inputRemote;
