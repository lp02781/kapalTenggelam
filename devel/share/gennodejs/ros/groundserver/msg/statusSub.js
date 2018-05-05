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

class statusSub {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.armDisarm = null;
      this.mode = null;
    }
    else {
      if (initObj.hasOwnProperty('armDisarm')) {
        this.armDisarm = initObj.armDisarm
      }
      else {
        this.armDisarm = false;
      }
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type statusSub
    // Serialize message field [armDisarm]
    bufferOffset = _serializer.bool(obj.armDisarm, buffer, bufferOffset);
    // Serialize message field [mode]
    bufferOffset = _serializer.int32(obj.mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type statusSub
    let len;
    let data = new statusSub(null);
    // Deserialize message field [armDisarm]
    data.armDisarm = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [mode]
    data.mode = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'groundserver/statusSub';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c4bbb9da5f572a607d9ab31c21067e0d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool armDisarm
    int32 mode
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new statusSub(null);
    if (msg.armDisarm !== undefined) {
      resolved.armDisarm = msg.armDisarm;
    }
    else {
      resolved.armDisarm = false
    }

    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    return resolved;
    }
};

module.exports = statusSub;
