require 'num4inte'

class Num4InteTest
    def initialize
        @h = 0.001
        @pi = Math::PI
        @func = Proc.new{|x|
            next 4 / (1 + x * x)
        }
    end
    def leftReimannSumMetodTest
        y = Num4InteLib.leftReimannSumMetod(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.1425924869231237
        puts
    end
    def rigtReimannSumMetodTest
        y = Num4InteLib.rigtReimannSumMetod(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.140592486923123
        puts
    end
    def newtonMethodTest
        y = Num4InteLib.newtonMethod(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.140592486923123
        puts
    end
end
tst = Num4InteTest.new
tst.leftReimannSumMetodTest()
tst.rigtReimannSumMetodTest()
tst.newtonMethodTest()

