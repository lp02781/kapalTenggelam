;; Auto-generated. Do not edit!


(when (boundp 'groundserver::arduinoInput)
  (if (not (find-package "GROUNDSERVER"))
    (make-package "GROUNDSERVER"))
  (shadow 'arduinoInput (find-package "GROUNDSERVER")))
(unless (find-package "GROUNDSERVER::ARDUINOINPUT")
  (make-package "GROUNDSERVER::ARDUINOINPUT"))

(in-package "ROS")
;;//! \htmlinclude arduinoInput.msg.html


(defclass groundserver::arduinoInput
  :super ros::object
  :slots (_arduYaw _arduThrottle _arduPitch _arduRoll _arduArmGripOn _arduArmGripOff _arduStabilizeMode _arduRemoteArmed ))

(defmethod groundserver::arduinoInput
  (:init
   (&key
    ((:arduYaw __arduYaw) 0.0)
    ((:arduThrottle __arduThrottle) 0.0)
    ((:arduPitch __arduPitch) 0.0)
    ((:arduRoll __arduRoll) 0.0)
    ((:arduArmGripOn __arduArmGripOn) 0)
    ((:arduArmGripOff __arduArmGripOff) 0)
    ((:arduStabilizeMode __arduStabilizeMode) 0)
    ((:arduRemoteArmed __arduRemoteArmed) 0)
    )
   (send-super :init)
   (setq _arduYaw (float __arduYaw))
   (setq _arduThrottle (float __arduThrottle))
   (setq _arduPitch (float __arduPitch))
   (setq _arduRoll (float __arduRoll))
   (setq _arduArmGripOn (round __arduArmGripOn))
   (setq _arduArmGripOff (round __arduArmGripOff))
   (setq _arduStabilizeMode (round __arduStabilizeMode))
   (setq _arduRemoteArmed (round __arduRemoteArmed))
   self)
  (:arduYaw
   (&optional __arduYaw)
   (if __arduYaw (setq _arduYaw __arduYaw)) _arduYaw)
  (:arduThrottle
   (&optional __arduThrottle)
   (if __arduThrottle (setq _arduThrottle __arduThrottle)) _arduThrottle)
  (:arduPitch
   (&optional __arduPitch)
   (if __arduPitch (setq _arduPitch __arduPitch)) _arduPitch)
  (:arduRoll
   (&optional __arduRoll)
   (if __arduRoll (setq _arduRoll __arduRoll)) _arduRoll)
  (:arduArmGripOn
   (&optional __arduArmGripOn)
   (if __arduArmGripOn (setq _arduArmGripOn __arduArmGripOn)) _arduArmGripOn)
  (:arduArmGripOff
   (&optional __arduArmGripOff)
   (if __arduArmGripOff (setq _arduArmGripOff __arduArmGripOff)) _arduArmGripOff)
  (:arduStabilizeMode
   (&optional __arduStabilizeMode)
   (if __arduStabilizeMode (setq _arduStabilizeMode __arduStabilizeMode)) _arduStabilizeMode)
  (:arduRemoteArmed
   (&optional __arduRemoteArmed)
   (if __arduRemoteArmed (setq _arduRemoteArmed __arduRemoteArmed)) _arduRemoteArmed)
  (:serialization-length
   ()
   (+
    ;; float32 _arduYaw
    4
    ;; float32 _arduThrottle
    4
    ;; float32 _arduPitch
    4
    ;; float32 _arduRoll
    4
    ;; int32 _arduArmGripOn
    4
    ;; int32 _arduArmGripOff
    4
    ;; int32 _arduStabilizeMode
    4
    ;; int32 _arduRemoteArmed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _arduYaw
       (sys::poke _arduYaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arduThrottle
       (sys::poke _arduThrottle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arduPitch
       (sys::poke _arduPitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arduRoll
       (sys::poke _arduRoll (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _arduArmGripOn
       (write-long _arduArmGripOn s)
     ;; int32 _arduArmGripOff
       (write-long _arduArmGripOff s)
     ;; int32 _arduStabilizeMode
       (write-long _arduStabilizeMode s)
     ;; int32 _arduRemoteArmed
       (write-long _arduRemoteArmed s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _arduYaw
     (setq _arduYaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arduThrottle
     (setq _arduThrottle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arduPitch
     (setq _arduPitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arduRoll
     (setq _arduRoll (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _arduArmGripOn
     (setq _arduArmGripOn (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _arduArmGripOff
     (setq _arduArmGripOff (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _arduStabilizeMode
     (setq _arduStabilizeMode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _arduRemoteArmed
     (setq _arduRemoteArmed (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get groundserver::arduinoInput :md5sum-) "444e27210a1cc7337dd2f2ca6321c819")
(setf (get groundserver::arduinoInput :datatype-) "groundserver/arduinoInput")
(setf (get groundserver::arduinoInput :definition-)
      "float32 arduYaw 
float32 arduThrottle
float32 arduPitch
float32 arduRoll
int32 arduArmGripOn
int32 arduArmGripOff
int32 arduStabilizeMode
int32 arduRemoteArmed

")



(provide :groundserver/arduinoInput "444e27210a1cc7337dd2f2ca6321c819")


