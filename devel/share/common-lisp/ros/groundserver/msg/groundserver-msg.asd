
(cl:in-package :asdf)

(defsystem "groundserver-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "arduinoInput" :depends-on ("_package_arduinoInput"))
    (:file "_package_arduinoInput" :depends-on ("_package"))
    (:file "extArdu" :depends-on ("_package_extArdu"))
    (:file "_package_extArdu" :depends-on ("_package"))
    (:file "inputRemote" :depends-on ("_package_inputRemote"))
    (:file "_package_inputRemote" :depends-on ("_package"))
    (:file "statusSub" :depends-on ("_package_statusSub"))
    (:file "_package_statusSub" :depends-on ("_package"))
    (:file "usbIp" :depends-on ("_package_usbIp"))
    (:file "_package_usbIp" :depends-on ("_package"))
  ))