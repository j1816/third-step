require "narray"

class Array
  # 要素をto_iした値の平均を算出する
  def sum
    inject(0.0){|r,i| r+=i.to_i }
  end
  # 要素をto_iした値の平均を算出する
  def avg
    inject(0.0){|r,i| r+=i.to_i }/size
  end
  # 要素をto_iした値の分散を算出する
  def variance
    a = avg
    inject(0.0){|r,i| r+=(i.to_i-a)**2 }/size
  end
  # 要素をto_iした値の標準偏差を算出する
  def standard_deviation
    Math.sqrt(variance)
  end
end

sci=[65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
eng=[44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

print "理科\n"
print "合計："
p sci.sum
print "平均：" 
p sci.avg
print "標準偏差：" 
p sci.standard_deviation

print "\n"

print "英語\n"
print "合計："
p eng.sum
print "平均：" 
p eng.avg
print "標準偏差：" 
p eng.standard_deviation
