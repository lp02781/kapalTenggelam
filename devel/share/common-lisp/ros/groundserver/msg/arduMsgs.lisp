; Auto-generated. Do not edit!


(cl:in-package groundserver-msg)


;//! \htmlinclude arduMsgs.msg.html

(cl:defclass <arduMsgs> (roslisp-msg-protocol:ros-message)
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
   (arduArmRoll
    :reader arduArmRoll
    :initarg :arduArmRoll
    :type cl:integer
    :initform 0)
   (arduLedOnOff
    :reader arduLedOnOff
    :initarg :arduLedOnOff
    :type cl:integer
    :initform 0))
)

(cl:defclass arduMsgs (<arduMsgs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <arduMsgs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'arduMsgs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name groundserver-msg:<arduMsgs> is deprecated: use groundserver-msg:arduMsgs instead.")))

(cl:ensure-generic-function 'arduYaw-val :lambda-list '(m))
(cl:defmethod arduYaw-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduYaw-val is deprecated.  Use groundserver-msg:arduYaw instead.")
  (arduYaw m))

(cl:ensure-generic-function 'arduThrottle-val :lambda-list '(m))
(cl:defmethod arduThrottle-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduThrottle-val is deprecated.  Use groundserver-msg:arduThrottle instead.")
  (arduThrottle m))

(cl:ensure-generic-function 'arduPitch-val :lambda-list '(m))
(cl:defmethod arduPitch-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduPitch-val is deprecated.  Use groundserver-msg:arduPitch instead.")
  (arduPitch m))

(cl:ensure-generic-function 'arduRoll-val :lambda-list '(m))
(cl:defmethod arduRoll-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduRoll-val is deprecated.  Use groundserver-msg:arduRoll instead.")
  (arduRoll m))

(cl:ensure-generic-function 'arduArmGripOn-val :lambda-list '(m))
(cl:defmethod arduArmGripOn-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduArmGripOn-val is deprecated.  Use groundserver-msg:arduArmGripOn instead.")
  (arduArmGripOn m))

(cl:ensure-generic-function 'arduArmGripOff-val :lambda-list '(m))
(cl:defmethod arduArmGripOff-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduArmGripOff-val is deprecated.  Use groundserver-msg:arduArmGripOff instead.")
  (arduArmGripOff m))

(cl:ensure-generic-function 'arduArmRoll-val :lambda-list '(m))
(cl:defmethod arduArmRoll-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduArmRoll-val is deprecated.  Use groundserver-msg:arduArmRoll instead.")
  (arduArmRoll m))

(cl:ensure-generic-function 'arduLedOnOff-val :lambda-list '(m))
(cl:defmethod arduLedOnOff-val ((m <arduMsgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:arduLedOnOff-val is deprecated.  Use groundserver-msg:arduLedOnOff instead.")
  (arduLedOnOff m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <arduMsgs>) ostream)
  "Serializes a message object of type '<arduMsgs>"
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
  (cl:let* ((signed (cl:slot-value msg 'arduArmRoll)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arduLedOnOff)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <arduMsgs>) istream)
  "Deserializes a message object of type '<arduMsgs>"
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
      (cl:setf (cl:slot-value msg 'arduArmRoll) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arduLedOnOff) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<arduMsgs>)))
  "Returns string type for a message object of type '<arduMsgs>"
  "groundserver/arduMsgs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'arduMsgs)))
  "Returns string type for a message object of type 'arduMsgs"
  "groundserver/arduMsgs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<arduMsgs>)))
  "Returns md5sum for a message object of type '<arduMsgs>"
  "8be09c0c14bfbf4e4fcbd8778a348742")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'arduMsgs)))
  "Returns md5sum for a message object of type 'arduMsgs"
  "8be09c0c14bfbf4e4fcbd8778a348742")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<arduMsgs>)))
  "Returns full string definition for message of type '<arduMsgs>"
  (cl:format cl:nil "float32 arduYaw ~%float32 arduThrottle~%float32 arduPitch~%float32 arduRoll~%int32 arduArmGripOn~%int32 arduArmGripOff~%int32 arduArmRoll~%int32 arduLedOnOff~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'arduMsgs)))
  "Returns full string definition for message of type 'arduMsgs"
  (cl:format cl:nil "float32 arduYaw ~%float32 arduThrottle~%float32 arduPitch~%float32 arduRoll~%int32 arduArmGripOn~%int32 arduArmGripOff~%int32 arduArmRoll~%int32 arduLedOnOff~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <arduMsgs>))
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
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <arduMsgs>))
  "Converts a ROS message object to a list"
  (cl:list 'arduMsgs
    (cl:cons ':arduYaw (arduYaw msg))
    (cl:cons ':arduThrottle (arduThrottle msg))
    (cl:cons ':arduPitch (arduPitch msg))
    (cl:cons ':arduRoll (arduRoll msg))
    (cl:cons ':arduArmGripOn (arduArmGripOn msg))
    (cl:cons ':arduArmGripOff (arduArmGripOff msg))
    (cl:cons ':arduArmRoll (arduArmRoll msg))
    (cl:cons ':arduLedOnOff (arduLedOnOff msg))
))
