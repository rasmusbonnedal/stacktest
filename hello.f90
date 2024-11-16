recursive function foo(n) result(res)
    implicit none
    external getstackusage
    integer :: n, res
    integer :: getstackusage

    print *, 'In foo(', n, '), stack usage: ', getstackusage()

    if (n > 0) then
        res = n + foo(n - 1)
    else
        res = 1
    end if
end function foo

program hello
    implicit none
    external initstackcheck
    integer :: foo, x
    
    call initstackcheck()
    x = foo(20)
    print *, x
end program hello
