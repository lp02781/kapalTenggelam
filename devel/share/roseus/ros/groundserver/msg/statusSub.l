;; Auto-generated. Do not edit!


(when (boundp 'groundserver::statusSub)
  (if (not (find-package "GROUNDSERVER"))
    (make-package "GROUNDSERVER"))
  (shadow 'statusSub (find-package "GROUNDSERVER")))
(unless (find-package "GROUNDSERVER::STATUSSUB")
  (make-package "GROUNDSERVER::STATUSSUB"))

(in-package "ROS")
;;//! \htmlinclude statusSub.msg.html


(defclass groundserver::statusSub
  :super ros::object
  :slots (_armDisarm _mode ))

(defmethod groundserver::statusSub
  (:init
   (&key
    ((:armDisarm __armDisarm) nil)
    ((:mode __mode) 0)
    )
   (send-super :init)
   (setq _armDisarm __armDisarm)
   (setq _mode (round __mode))
   self)
  (:armDisarm
   (&optional __armDisarm)
   (if __armDisarm (setq _armDisarm __armDisarm)) _armDisarm)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:serialization-length
   ()
   (+
    ;; bool _armDisarm
    1
    ;; int32 _mode
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _armDisarm
       (if _armDisarm (write-byte -1 s) (write-byte 0 s))
     ;; int32 _mode
       (write-long _mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _armDisarm
     (setq _armDisarm (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _mode
     (setq _mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get groundserver::statusSub :md5sum-) "c4bbb9da5f572a607d9ab31c21067e0d")
(setf (get groundserver::statusSub :datatype-) "groundserver/statusSub")
(setf (get groundserver::statusSub :definition-)
      "bool armDisarm
int32 mode

")



(provide :groundserver/statusSub "c4bbb9da5f572a607d9ab31c21067e0d")


