# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from groundserver/inputRemote.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class inputRemote(genpy.Message):
  _md5sum = "60b79f3a2f7dab179828919f073b14bf"
  _type = "groundserver/inputRemote"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int8 codeYaw 
int8 codeThrottle
int8 codePitch
int8 codeRoll
int8 codeArmGripOn
int8 codeArmGripOff
int8 codeStabilizeMode
int8 codeRemoteArmed
"""
  __slots__ = ['codeYaw','codeThrottle','codePitch','codeRoll','codeArmGripOn','codeArmGripOff','codeStabilizeMode','codeRemoteArmed']
  _slot_types = ['int8','int8','int8','int8','int8','int8','int8','int8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       codeYaw,codeThrottle,codePitch,codeRoll,codeArmGripOn,codeArmGripOff,codeStabilizeMode,codeRemoteArmed

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(inputRemote, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.codeYaw is None:
        self.codeYaw = 0
      if self.codeThrottle is None:
        self.codeThrottle = 0
      if self.codePitch is None:
        self.codePitch = 0
      if self.codeRoll is None:
        self.codeRoll = 0
      if self.codeArmGripOn is None:
        self.codeArmGripOn = 0
      if self.codeArmGripOff is None:
        self.codeArmGripOff = 0
      if self.codeStabilizeMode is None:
        self.codeStabilizeMode = 0
      if self.codeRemoteArmed is None:
        self.codeRemoteArmed = 0
    else:
      self.codeYaw = 0
      self.codeThrottle = 0
      self.codePitch = 0
      self.codeRoll = 0
      self.codeArmGripOn = 0
      self.codeArmGripOff = 0
      self.codeStabilizeMode = 0
      self.codeRemoteArmed = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_8b().pack(_x.codeYaw, _x.codeThrottle, _x.codePitch, _x.codeRoll, _x.codeArmGripOn, _x.codeArmGripOff, _x.codeStabilizeMode, _x.codeRemoteArmed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.codeYaw, _x.codeThrottle, _x.codePitch, _x.codeRoll, _x.codeArmGripOn, _x.codeArmGripOff, _x.codeStabilizeMode, _x.codeRemoteArmed,) = _get_struct_8b().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_8b().pack(_x.codeYaw, _x.codeThrottle, _x.codePitch, _x.codeRoll, _x.codeArmGripOn, _x.codeArmGripOff, _x.codeStabilizeMode, _x.codeRemoteArmed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.codeYaw, _x.codeThrottle, _x.codePitch, _x.codeRoll, _x.codeArmGripOn, _x.codeArmGripOff, _x.codeStabilizeMode, _x.codeRemoteArmed,) = _get_struct_8b().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_8b = None
def _get_struct_8b():
    global _struct_8b
    if _struct_8b is None:
        _struct_8b = struct.Struct("<8b")
    return _struct_8b
