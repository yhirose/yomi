#!/usr/bin/env ruby
# -*- encoding: utf-8 -*-
    
require 'nokogiri'
require 'open-uri'

res = $stdin

doc = Nokogiri::HTML(res)

title = doc.css('p.st').inner_text

body = []
doc.css('p').each do |el|
    klass = el['class']
    text = el.inner_text.gsub(/\s+/, ' ')
    body.push "<p class=\"#{klass}\">#{text}</p>" unless text.empty?
end

html = <<EOS
<DOCTYPE html>
<html>
<head>
<title>#{title}</title>
<meta charset='utf-8' />
<style>
.st, .ss {
  text-align: center;
  font-weight: bold;
}
</style>
</head>
<body>
#{body.join("\n")}
</body>
</html>
EOS

print html
