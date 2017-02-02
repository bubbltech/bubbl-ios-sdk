Pod::Spec.new do |s|
  s.name         = "Bubbl"
  s.version      = "1.0.0"
  s.summary      = "Bubbl is an iOS SDK with a sophisticated, highly accurate, geofence activation cloud-based campaign and analytics platform."
  s.description  = <<-DESC
  						* Bubbl is an iOS and Android SDK with a sophisticated, highly accurate, geofence activation cloud-based campaign and analytics platform. 
  						* Whether 5sqm or an island, lock down your location and set the features and tools you want to use. 
  						* Pick and mix from the features we already offer or we can custom develop engagement tools that are unique to your brand.
                   DESC

  s.homepage     = "http://bubbl.tech"
  s.license      = "Copyright 2017 Bubbl LTD"
  s.author             = { "Bubbl LTD" => "support@bubbl.tech" }
  s.platform     = :ios, "9.0"
  s.source       = { :git => "https://andyzaharia@bitbucket.org/andyzaharia/bubbl.git", :tag => "1.0.0" }
  s.ios.vendored_framework = 'Bubbl.framework'
  s.requires_arc = true
end
