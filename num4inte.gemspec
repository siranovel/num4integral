Gem::Specification.new do |s|
  s.name        = 'num4inte'
  s.version     = '0.1.2'
  s.date        = '2023-05-24'
  s.summary     = "num for integral"
  s.description = "numerical solution for integral"
  s.authors     = ["siranovel"]
  s.email       = "siranovel@gmail.com"
  s.homepage    = "http://github.com/siranovel/num4integral"
  s.metadata    = {
      'changelog_uri'     => s.homepage + '/blob/main/CHANGELOG.md',
      'documentation_uri' => "https://rubydoc.info/gems/#{s.name}/#{s.version}",
      'homepage_uri'      => s.homepage,
      'wiki_uri'          => 'https://github.com/siranovel/mydocs/tree/main/num4integral',
  }
  s.license     = "MIT"
  s.files       = ["LICENSE", "Gemfile", "CHANGELOG.md"]
  s.files       += Dir.glob("{lib,ext}/**/*")
  s.extensions  = %w[ext/num4inte/Rakefile]
  s.add_dependency 'ffi-compiler', '~> 1.0', '>= 1.0.1'
  s.add_development_dependency 'rake', '~> 12.3', '>= 12.3.3'
end
