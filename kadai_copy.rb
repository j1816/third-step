require "narray"

def std(arr)
  avg = arr.sum/arr.length
  arr1 = arr.map{|x| (x - avg) ** 2}
  return Mat.sqrt(arr1.sum / arr.length).round(2)
end

#############################
science=[65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
english=[44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

sum_sci = science.sum.to_f
sum_eng = english.sum.to_f

avg_sci = NArray.to_na([65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70])
avg_eng = NArray.to_na([44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84])

std_src = std(science)
std_eng = std(english)

print "理科\n"
print "合計："
p sum_sci
print "平均：" 
p avg_sci.mean
print "標準偏差：" 
p std_sci

print "英語\n"
print "合計："
p sum_eng
print "平均：" 
p avg_eng.mean
print "標準偏差：" 
p std_eng
