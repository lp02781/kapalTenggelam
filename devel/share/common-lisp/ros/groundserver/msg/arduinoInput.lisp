; Auto-generated. Do not edit!


(cl:in-package groundserver-msg)


;//! \htmlinclude arduinoInput.msg.html

(cl:defclass <arduinoInput> (roslisp-msg-protocol:ros-message)
  ((arduYaw
    :reader arduYaw
    :initarg :arduYaw
    :type cl:float
    :initform 0.0)
   (arduThrottle
    :reader arduThrottle
    :initarg :arduThrottle
    :type cl:float
    :initform 0.0)
   (arduPitch
    :reader arduPitch
    :initarg :arduPitch
    :type cl:float
    :initform 0.0)
   (arduRoll
    :reader arduRoll
    :initarg :arduRoll
    :type cl:float
    :initform 0.0)
   (arduArmGripOn
    :reader arduArmGripOn
    :initarg :arduArmGripOn
    :type cl:integer
    :initform 0)
   (arduArmGripOff
    :reader arduArmGripOff
    :initarg :arduArmGripOff
    :type cl:integer
    :initform 0)
   (arduStabilizeMode
    :reader arduStabilizeMode
    :initarg :arduStabilizeMode
    :type cl:integer
    :initform 0)
   (arduRemoteArmed
    :reader arduRemoteArmed
    :initarg :arduRemoteArmed
    :type cl:integer
    :initform 0))
)

(cl:defclass arduinoInput (<arduinoInput>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <arduinoInput>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'arduinoInput)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name groundserver-msg:<arduinoInput> is deprecated: use groundserver-msg:arduinoInput instead.")))

(cl:ensure-generic-function 'arduYaw-val :lambda-list '(m))
(cl:defmethod arduYaw-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduYaw-val is deprecated.  Use groundserver-msg:arduYaw instead.")
  (arduYaw m))

(cl:ensure-generic-function 'arduThrottle-val :lambda-list '(m))
(cl:defmethod arduThrottle-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduThrottle-val is deprecated.  Use groundserver-msg:arduThrottle instead.")
  (arduThrottle m))

(cl:ensure-generic-function 'arduPitch-val :lambda-list '(m))
(cl:defmethod arduPitch-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduPitch-val is deprecated.  Use groundserver-msg:arduPitch instead.")
  (arduPitch m))

(cl:ensure-generic-function 'arduRoll-val :lambda-list '(m))
(cl:defmethod arduRoll-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduRoll-val is deprecated.  Use groundserver-msg:arduRoll instead.")
  (arduRoll m))

(cl:ensure-generic-function 'arduArmGripOn-val :lambda-list '(m))
(cl:defmethod arduArmGripOn-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduArmGripOn-val is deprecated.  Use groundserver-msg:arduArmGripOn instead.")
  (arduArmGripOn m))

(cl:ensure-generic-function 'arduArmGripOff-val :lambda-list '(m))
(cl:defmethod arduArmGripOff-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduArmGripOff-val is deprecated.  Use groundserver-msg:arduArmGripOff instead.")
  (arduArmGripOff m))

(cl:ensure-generic-function 'arduStabilizeMode-val :lambda-list '(m))
(cl:defmethod arduStabilizeMode-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduStabilizeMode-val is deprecated.  Use groundserver-msg:arduStabilizeMode instead.")
  (arduStabilizeMode m))

(cl:ensure-generic-function 'arduRemoteArmed-val :lambda-list '(m))
(cl:defmethod arduRemoteArmed-val ((m <arduinoInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduRemoteArmed-val is deprecated.  Use groundserver-msg:arduRemoteArmed instead.")
  (arduRemoteArmed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <arduinoInput>) ostream)
  "Serializes a message object of type '<arduinoInput>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'arduYaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'arduThrottle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'arduPitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'arduRoll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'arduArmGripOn)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arduArmGripOff)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arduStabilizeMode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arduRemoteArmed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <arduinoInput>) istream)
  "Deserializes a message object of type '<arduinoInput>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'arduYaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'arduThrottle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'arduPitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'arduRoll) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arduArmGripOn) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arduArmGripOff) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arduStabilizeMode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arduRemoteArmed) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<arduinoInput>)))
  "Returns string type for a message object of type '<arduinoInput>"
  "groundserver/arduinoInput")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'arduinoInput)))
  "Returns string type for a message object of type 'arduinoInput"
  "groundserver/arduinoInput")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<arduinoInput>)))
  "Returns md5sum for a message object of type '<arduinoInput>"
  "444e27210a1cc7337dd2f2ca6321c819")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'arduinoInput)))
  "Returns md5sum for a message object of type 'arduinoInput"
  "444e27210a1cc7337dd2f2ca6321c819")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<arduinoInput>)))
  "Returns full string definition for message of type '<arduinoInput>"
  (cl:format cl:nil "float32 arduYaw ~%float32 arduThrottle~%float32 arduPitch~%float32 arduRoll~%int32 arduArmGripOn~%int32 arduArmGripOff~%int32 arduStabilizeMode~%int32 arduRemoteArmed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'arduinoInput)))
  "Returns full string definition for message of type 'arduinoInput"
  (cl:format cl:nil "float32 arduYaw ~%float32 arduThrottle~%float32 arduPitch~%float32 arduRoll~%int32 arduArmGripOn~%int32 arduArmGripOff~%int32 arduStabilizeMode~%int32 arduRemoteArmed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <arduinoInput>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <arduinoInput>))
  "Converts a ROS message object to a list"
  (cl:list 'arduinoInput
    (cl:cons ':arduYaw (arduYaw msg))
    (cl:cons ':arduThrottle (arduThrottle msg))
    (cl:cons ':arduPitch (arduPitch msg))
    (cl:cons ':arduRoll (arduRoll msg))
    (cl:cons ':arduArmGripOn (arduArmGripOn msg))
    (cl:cons ':arduArmGripOff (arduArmGripOff msg))
    (cl:cons ':arduStabilizeMode (arduStabilizeMode msg))
    (cl:cons ':arduRemoteArmed (arduRemoteArmed msg))
))
