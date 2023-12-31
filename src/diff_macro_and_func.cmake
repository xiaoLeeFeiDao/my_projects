cmake_minimum_required(VERSION 3.5)
set(var "ABC")
# 定义的这个宏的例子太扯了，不好理解
macro(Moo arg) #这里的arg被下面调用的传入${var}替换了
  message("arg = ${arg}") # 相当于 message("arg = ${${var}}")，${${var}}等价于${"ABC"}
  message("# After change the value of arg.")
  set(arg "def") # 这里相当于 set(${${var}} "def") == set("ABC" "def")
  message("arg = ${arg}") # 这里修改arg的值是不成功的，因为上一步已经将arg替换了
  set(var "xyz")
  message("var = ${var}")
endmacro()
message("=== Call macro ===")
Moo(${var})

function(Foo arg)
  message("arg = ${arg}")
  set(arg "abc")
  message("# After change the value of arg.")
  message("arg = ${arg}")
endfunction()
message("=== Call function ===")
# Foo(${var})
Foo(var)