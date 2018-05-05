; Auto-generated. Do not edit!


(cl:in-package groundserver-msg)


;//! \htmlinclude usbIp.msg.html

(cl:defclass <usbIp> (roslisp-msg-protocol:ros-message)
  ((throttle
    :reader throttle
    :initarg :throttle
    :type cl:float
    :initform 0.0)
   (steering
    :reader steering
    :initarg :steering
    :type cl:float
    :initform 0.0)
   (servoGrip
    :reader servoGrip
    :initarg :servoGrip
    :type cl:float
    :initform 0.0)
   (altitude
    :reader altitude
    :initarg :altitude
    :type cl:float
    :initform 0.0))
)

(cl:defclass usbIp (<usbIp>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <usbIp>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'usbIp)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name groundserver-msg:<usbIp> is deprecated: use groundserver-msg:usbIp instead.")))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <usbIp>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:throttle-val is deprecated.  Use groundserver-msg:throttle instead.")
  (throttle m))

(cl:ensure-generic-function 'steering-val :lambda-list '(m))
(cl:defmethod steering-val ((m <usbIp>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:steering-val is deprecated.  Use groundserver-msg:steering instead.")
  (steering m))

(cl:ensure-generic-function 'servoGrip-val :lambda-list '(m))
(cl:defmethod servoGrip-val ((m <usbIp>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:servoGrip-val is deprecated.  Use groundserver-msg:servoGrip instead.")
  (servoGrip m))

(cl:ensure-generic-function 'altitude-val :lambda-list '(m))
(cl:defmethod altitude-val ((m <usbIp>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:altitude-val is deprecated.  Use groundserver-msg:altitude instead.")
  (altitude m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <usbIp>) ostream)
  "Serializes a message object of type '<usbIp>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'steering))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'servoGrip))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'altitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <usbIp>) istream)
  "Deserializes a message object of type '<usbIp>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'throttle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steering) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'servoGrip) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'altitude) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<usbIp>)))
  "Returns string type for a message object of type '<usbIp>"
  "groundserver/usbIp")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'usbIp)))
  "Returns string type for a message object of type 'usbIp"
  "groundserver/usbIp")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<usbIp>)))
  "Returns md5sum for a message object of type '<usbIp>"
  "5a9b5f9885099077c58386bfdab1c9a0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'usbIp)))
  "Returns md5sum for a message object of type 'usbIp"
  "5a9b5f9885099077c58386bfdab1c9a0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<usbIp>)))
  "Returns full string definition for message of type '<usbIp>"
  (cl:format cl:nil "float32 throttle~%float32 steering~%float32 servoGrip~%float32 altitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'usbIp)))
  "Returns full string definition for message of type 'usbIp"
  (cl:format cl:nil "float32 throttle~%float32 steering~%float32 servoGrip~%float32 altitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <usbIp>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <usbIp>))
  "Converts a ROS message object to a list"
  (cl:list 'usbIp
    (cl:cons ':throttle (throttle msg))
    (cl:cons ':steering (steering msg))
    (cl:cons ':servoGrip (servoGrip msg))
    (cl:cons ':altitude (altitude msg))
))
