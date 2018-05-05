;; Auto-generated. Do not edit!


(when (boundp 'groundserver::inputRemote)
  (if (not (find-package "GROUNDSERVER"))
    (make-package "GROUNDSERVER"))
  (shadow 'inputRemote (find-package "GROUNDSERVER")))
(unless (find-package "GROUNDSERVER::INPUTREMOTE")
  (make-package "GROUNDSERVER::INPUTREMOTE"))

(in-package "ROS")
;;//! \htmlinclude inputRemote.msg.html


(defclass groundserver::inputRemote
  :super ros::object
  :slots (_codeYaw _codeThrottle _codePitch _codeRoll _codeArmGripOn _codeArmGripOff _codeStabilizeMode _codeRemoteArmed ))

(defmethod groundserver::inputRemote
  (:init
   (&key
    ((:codeYaw __codeYaw) 0)
    ((:codeThrottle __codeThrottle) 0)
    ((:codePitch __codePitch) 0)
    ((:codeRoll __codeRoll) 0)
    ((:codeArmGripOn __codeArmGripOn) 0)
    ((:codeArmGripOff __codeArmGripOff) 0)
    ((:codeStabilizeMode __codeStabilizeMode) 0)
    ((:codeRemoteArmed __codeRemoteArmed) 0)
    )
   (send-super :init)
   (setq _codeYaw (round __codeYaw))
   (setq _codeThrottle (round __codeThrottle))
   (setq _codePitch (round __codePitch))
   (setq _codeRoll (round __codeRoll))
   (setq _codeArmGripOn (round __codeArmGripOn))
   (setq _codeArmGripOff (round __codeArmGripOff))
   (setq _codeStabilizeMode (round __codeStabilizeMode))
   (setq _codeRemoteArmed (round __codeRemoteArmed))
   self)
  (:codeYaw
   (&optional __codeYaw)
   (if __codeYaw (setq _codeYaw __codeYaw)) _codeYaw)
  (:codeThrottle
   (&optional __codeThrottle)
   (if __codeThrottle (setq _codeThrottle __codeThrottle)) _codeThrottle)
  (:codePitch
   (&optional __codePitch)
   (if __codePitch (setq _codePitch __codePitch)) _codePitch)
  (:codeRoll
   (&optional __codeRoll)
   (if __codeRoll (setq _codeRoll __codeRoll)) _codeRoll)
  (:codeArmGripOn
   (&optional __codeArmGripOn)
   (if __codeArmGripOn (setq _codeArmGripOn __codeArmGripOn)) _codeArmGripOn)
  (:codeArmGripOff
   (&optional __codeArmGripOff)
   (if __codeArmGripOff (setq _codeArmGripOff __codeArmGripOff)) _codeArmGripOff)
  (:codeStabilizeMode
   (&optional __codeStabilizeMode)
   (if __codeStabilizeMode (setq _codeStabilizeMode __codeStabilizeMode)) _codeStabilizeMode)
  (:codeRemoteArmed
   (&optional __codeRemoteArmed)
   (if __codeRemoteArmed (setq _codeRemoteArmed __codeRemoteArmed)) _codeRemoteArmed)
  (:serialization-length
   ()
   (+
    ;; int8 _codeYaw
    1
    ;; int8 _codeThrottle
    1
    ;; int8 _codePitch
    1
    ;; int8 _codeRoll
    1
    ;; int8 _codeArmGripOn
    1
    ;; int8 _codeArmGripOff
    1
    ;; int8 _codeStabilizeMode
    1
    ;; int8 _codeRemoteArmed
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _codeYaw
       (write-byte _codeYaw s)
     ;; int8 _codeThrottle
       (write-byte _codeThrottle s)
     ;; int8 _codePitch
       (write-byte _codePitch s)
     ;; int8 _codeRoll
       (write-byte _codeRoll s)
     ;; int8 _codeArmGripOn
       (write-byte _codeArmGripOn s)
     ;; int8 _codeArmGripOff
       (write-byte _codeArmGripOff s)
     ;; int8 _codeStabilizeMode
       (write-byte _codeStabilizeMode s)
     ;; int8 _codeRemoteArmed
       (write-byte _codeRemoteArmed s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _codeYaw
     (setq _codeYaw (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codeYaw 127) (setq _codeYaw (- _codeYaw 256)))
   ;; int8 _codeThrottle
     (setq _codeThrottle (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codeThrottle 127) (setq _codeThrottle (- _codeThrottle 256)))
   ;; int8 _codePitch
     (setq _codePitch (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codePitch 127) (setq _codePitch (- _codePitch 256)))
   ;; int8 _codeRoll
     (setq _codeRoll (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codeRoll 127) (setq _codeRoll (- _codeRoll 256)))
   ;; int8 _codeArmGripOn
     (setq _codeArmGripOn (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codeArmGripOn 127) (setq _codeArmGripOn (- _codeArmGripOn 256)))
   ;; int8 _codeArmGripOff
     (setq _codeArmGripOff (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codeArmGripOff 127) (setq _codeArmGripOff (- _codeArmGripOff 256)))
   ;; int8 _codeStabilizeMode
     (setq _codeStabilizeMode (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codeStabilizeMode 127) (setq _codeStabilizeMode (- _codeStabilizeMode 256)))
   ;; int8 _codeRemoteArmed
     (setq _codeRemoteArmed (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _codeRemoteArmed 127) (setq _codeRemoteArmed (- _codeRemoteArmed 256)))
   ;;
   self)
  )

(setf (get groundserver::inputRemote :md5sum-) "60b79f3a2f7dab179828919f073b14bf")
(setf (get groundserver::inputRemote :datatype-) "groundserver/inputRemote")
(setf (get groundserver::inputRemote :definition-)
      "int8 codeYaw 
int8 codeThrottle
int8 codePitch
int8 codeRoll
int8 codeArmGripOn
int8 codeArmGripOff
int8 codeStabilizeMode
int8 codeRemoteArmed

")



(provide :groundserver/inputRemote "60b79f3a2f7dab179828919f073b14bf")


