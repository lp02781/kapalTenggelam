;; Auto-generated. Do not edit!


(when (boundp 'groundserver::usbIp)
  (if (not (find-package "GROUNDSERVER"))
    (make-package "GROUNDSERVER"))
  (shadow 'usbIp (find-package "GROUNDSERVER")))
(unless (find-package "GROUNDSERVER::USBIP")
  (make-package "GROUNDSERVER::USBIP"))

(in-package "ROS")
;;//! \htmlinclude usbIp.msg.html


(defclass groundserver::usbIp
  :super ros::object
  :slots (_throttle _steering _servoGrip _altitude ))

(defmethod groundserver::usbIp
  (:init
   (&key
    ((:throttle __throttle) 0.0)
    ((:steering __steering) 0.0)
    ((:servoGrip __servoGrip) 0.0)
    ((:altitude __altitude) 0.0)
    )
   (send-super :init)
   (setq _throttle (float __throttle))
   (setq _steering (float __steering))
   (setq _servoGrip (float __servoGrip))
   (setq _altitude (float __altitude))
   self)
  (:throttle
   (&optional __throttle)
   (if __throttle (setq _throttle __throttle)) _throttle)
  (:steering
   (&optional __steering)
   (if __steering (setq _steering __steering)) _steering)
  (:servoGrip
   (&optional __servoGrip)
   (if __servoGrip (setq _servoGrip __servoGrip)) _servoGrip)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:serialization-length
   ()
   (+
    ;; float32 _throttle
    4
    ;; float32 _steering
    4
    ;; float32 _servoGrip
    4
    ;; float32 _altitude
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _throttle
       (sys::poke _throttle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _steering
       (sys::poke _steering (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _servoGrip
       (sys::poke _servoGrip (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _throttle
     (setq _throttle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _steering
     (setq _steering (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _servoGrip
     (setq _servoGrip (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _altitude
     (setq _altitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get groundserver::usbIp :md5sum-) "5a9b5f9885099077c58386bfdab1c9a0")
(setf (get groundserver::usbIp :datatype-) "groundserver/usbIp")
(setf (get groundserver::usbIp :definition-)
      "float32 throttle
float32 steering
float32 servoGrip
float32 altitude

")



(provide :groundserver/usbIp "5a9b5f9885099077c58386bfdab1c9a0")


