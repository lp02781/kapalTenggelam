; Auto-generated. Do not edit!


(cl:in-package groundserver-msg)


;//! \htmlinclude inputRemote.msg.html

(cl:defclass <inputRemote> (roslisp-msg-protocol:ros-message)
  ((codeYaw
    :reader codeYaw
    :initarg :codeYaw
    :type cl:fixnum
    :initform 0)
   (codeThrottle
    :reader codeThrottle
    :initarg :codeThrottle
    :type cl:fixnum
    :initform 0)
   (codePitch
    :reader codePitch
    :initarg :codePitch
    :type cl:fixnum
    :initform 0)
   (codeRoll
    :reader codeRoll
    :initarg :codeRoll
    :type cl:fixnum
    :initform 0)
   (codeArmGripOn
    :reader codeArmGripOn
    :initarg :codeArmGripOn
    :type cl:fixnum
    :initform 0)
   (codeArmGripOff
    :reader codeArmGripOff
    :initarg :codeArmGripOff
    :type cl:fixnum
    :initform 0)
   (codeStabilizeMode
    :reader codeStabilizeMode
    :initarg :codeStabilizeMode
    :type cl:fixnum
    :initform 0)
   (codeRemoteArmed
    :reader codeRemoteArmed
    :initarg :codeRemoteArmed
    :type cl:fixnum
    :initform 0))
)

(cl:defclass inputRemote (<inputRemote>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <inputRemote>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'inputRemote)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name groundserver-msg:<inputRemote> is deprecated: use groundserver-msg:inputRemote instead.")))

(cl:ensure-generic-function 'codeYaw-val :lambda-list '(m))
(cl:defmethod codeYaw-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codeYaw-val is deprecated.  Use groundserver-msg:codeYaw instead.")
  (codeYaw m))

(cl:ensure-generic-function 'codeThrottle-val :lambda-list '(m))
(cl:defmethod codeThrottle-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codeThrottle-val is deprecated.  Use groundserver-msg:codeThrottle instead.")
  (codeThrottle m))

(cl:ensure-generic-function 'codePitch-val :lambda-list '(m))
(cl:defmethod codePitch-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codePitch-val is deprecated.  Use groundserver-msg:codePitch instead.")
  (codePitch m))

(cl:ensure-generic-function 'codeRoll-val :lambda-list '(m))
(cl:defmethod codeRoll-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codeRoll-val is deprecated.  Use groundserver-msg:codeRoll instead.")
  (codeRoll m))

(cl:ensure-generic-function 'codeArmGripOn-val :lambda-list '(m))
(cl:defmethod codeArmGripOn-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codeArmGripOn-val is deprecated.  Use groundserver-msg:codeArmGripOn instead.")
  (codeArmGripOn m))

(cl:ensure-generic-function 'codeArmGripOff-val :lambda-list '(m))
(cl:defmethod codeArmGripOff-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codeArmGripOff-val is deprecated.  Use groundserver-msg:codeArmGripOff instead.")
  (codeArmGripOff m))

(cl:ensure-generic-function 'codeStabilizeMode-val :lambda-list '(m))
(cl:defmethod codeStabilizeMode-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codeStabilizeMode-val is deprecated.  Use groundserver-msg:codeStabilizeMode instead.")
  (codeStabilizeMode m))

(cl:ensure-generic-function 'codeRemoteArmed-val :lambda-list '(m))
(cl:defmethod codeRemoteArmed-val ((m <inputRemote>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:codeRemoteArmed-val is deprecated.  Use groundserver-msg:codeRemoteArmed instead.")
  (codeRemoteArmed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <inputRemote>) ostream)
  "Serializes a message object of type '<inputRemote>"
  (cl:let* ((signed (cl:slot-value msg 'codeYaw)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'codeThrottle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'codePitch)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'codeRoll)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'codeArmGripOn)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'codeArmGripOff)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'codeStabilizeMode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'codeRemoteArmed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <inputRemote>) istream)
  "Deserializes a message object of type '<inputRemote>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codeYaw) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codeThrottle) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codePitch) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codeRoll) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codeArmGripOn) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codeArmGripOff) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codeStabilizeMode) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'codeRemoteArmed) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<inputRemote>)))
  "Returns string type for a message object of type '<inputRemote>"
  "groundserver/inputRemote")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'inputRemote)))
  "Returns string type for a message object of type 'inputRemote"
  "groundserver/inputRemote")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<inputRemote>)))
  "Returns md5sum for a message object of type '<inputRemote>"
  "60b79f3a2f7dab179828919f073b14bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'inputRemote)))
  "Returns md5sum for a message object of type 'inputRemote"
  "60b79f3a2f7dab179828919f073b14bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<inputRemote>)))
  "Returns full string definition for message of type '<inputRemote>"
  (cl:format cl:nil "int8 codeYaw ~%int8 codeThrottle~%int8 codePitch~%int8 codeRoll~%int8 codeArmGripOn~%int8 codeArmGripOff~%int8 codeStabilizeMode~%int8 codeRemoteArmed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'inputRemote)))
  "Returns full string definition for message of type 'inputRemote"
  (cl:format cl:nil "int8 codeYaw ~%int8 codeThrottle~%int8 codePitch~%int8 codeRoll~%int8 codeArmGripOn~%int8 codeArmGripOff~%int8 codeStabilizeMode~%int8 codeRemoteArmed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <inputRemote>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <inputRemote>))
  "Converts a ROS message object to a list"
  (cl:list 'inputRemote
    (cl:cons ':codeYaw (codeYaw msg))
    (cl:cons ':codeThrottle (codeThrottle msg))
    (cl:cons ':codePitch (codePitch msg))
    (cl:cons ':codeRoll (codeRoll msg))
    (cl:cons ':codeArmGripOn (codeArmGripOn msg))
    (cl:cons ':codeArmGripOff (codeArmGripOff msg))
    (cl:cons ':codeStabilizeMode (codeStabilizeMode msg))
    (cl:cons ':codeRemoteArmed (codeRemoteArmed msg))
))
