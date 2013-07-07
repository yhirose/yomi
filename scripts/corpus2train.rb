#!/usr/bin/env ruby
# -*- encoding: utf-8 -*-
    
$stdin.each do |line|
    # Break text into chunks, end escape '-' and '/'.
    # The chunk format is 'other{kanji|yomi}'
    chunks = line.chomp.gsub(/[-\/]/, '!').scan(/(.*?){(.*?)\|(.*?)}/)

    s = ''
    chunks.each do |other, kanji, yomi|
        # The training data format is
        # 'o~t~h~e~r|k-a-n-j-i/yomi|o~t~h~e~r|k-a-n-j-i/yomi|o~t~h~e~r'
        if other.length > 0
            s += '~' if s[-1] and s[-1] != '|'
            s += other.scan(/./).join('~')
        end
        if kanji.length > 0
            s += '|' if s[-1] and s[-1] != '|'
            s += '%s/%s|' % [kanji.scan(/./).join('-'), yomi]
        end
    end
    s.chop! if s[-1] == '|'

    puts s
end
