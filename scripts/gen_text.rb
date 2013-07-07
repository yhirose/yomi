#!/usr/bin/env ruby
# -*- encoding: utf-8 -*-
    
require 'nokogiri'
require 'open-uri'

res = $stdin

doc = Nokogiri::HTML(res)

title = doc.css('p.st').inner_text

pars = []
doc.css('p').each do |el|
    text = el.inner_text.gsub(/\s+/, ' ')
    pars.push text
end

print pars.join("\n")
