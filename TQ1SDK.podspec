Pod::Spec.new do |s|
s.name = "TQ1SDK"
s.version = "3.3.0-beta"
s.summary = "Library TQ1SDK to implement TQ1 on projects"
s.homepage = "https://github.com/tq1/taqtile-sdk-ios"
s.license = { :type => 'Comercial'}
s.author = { "Taqtile" => "felipe.sabino@taqtile.com" }
s.source = { :git => "git@github.com:tq1/br-tq1-ios.git", :tag => "" }
s.platform = :ios, '8.0'
s.requires_arc = true
s.source_files = 'TQ1SDK/Headers/*.h'
s.vendored_library = 'TQ1SDK/libTQ1SDK.a'
s.library = 'TQ1SDK'
s.library = 'sqlite3'
end
