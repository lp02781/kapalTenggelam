; Auto-generated. Do not edit!


(cl:in-package groundserver-msg)


;//! \htmlinclude statusSub.msg.html

(cl:defclass <statusSub> (roslisp-msg-protocol:ros-message)
  ((armDisarm
    :reader armDisarm
    :initarg :armDisarm
    :type cl:boolean
    :initform cl:nil)
   (mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0))
)

(cl:defclass statusSub (<statusSub>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <statusSub>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'statusSub)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name groundserver-msg:<statusSub> is deprecated: use groundserver-msg:statusSub instead.")))

(cl:ensure-generic-function 'armDisarm-val :lambda-list '(m))
(cl:defmethod armDisarm-val ((m <statusSub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:armDisarm-val is deprecated.  Use groundserver-msg:armDisarm instead.")
  (armDisarm m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <statusSub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader groundserver-msg:mode-val is deprecated.  Use groundserver-msg:mode instead.")
  (mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <statusSub>) ostream)
  "Serializes a message object of type '<statusSub>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'armDisarm) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <statusSub>) istream)
  "Deserializes a message object of type '<statusSub>"
    (cl:setf (cl:slot-value msg 'armDisarm) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<statusSub>)))
  "Returns string type for a message object of type '<statusSub>"
  "groundserver/statusSub")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'statusSub)))
  "Returns string type for a message object of type 'statusSub"
  "groundserver/statusSub")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<statusSub>)))
  "Returns md5sum for a message object of type '<statusSub>"
  "c4bbb9da5f572a607d9ab31c21067e0d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'statusSub)))
  "Returns md5sum for a message object of type 'statusSub"
  "c4bbb9da5f572a607d9ab31c21067e0d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<statusSub>)))
  "Returns full string definition for message of type '<statusSub>"
  (cl:format cl:nil "bool armDisarm~%int32 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'statusSub)))
  "Returns full string definition for message of type 'statusSub"
  (cl:format cl:nil "bool armDisarm~%int32 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <statusSub>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <statusSub>))
  "Converts a ROS message object to a list"
  (cl:list 'statusSub
    (cl:cons ':armDisarm (armDisarm msg))
    (cl:cons ':mode (mode msg))
))
