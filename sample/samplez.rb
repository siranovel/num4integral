require 'num4inte'

class Num4InteTest
    def initialize
        @h = 0.001
        @pi = Math::PI
        @func = Proc.new{|x|
            next 4 / (1 + x * x)
        }
    end
    def leftReimannSumMethodTest
        y = Num4InteLib.leftReimannSumMethod(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.1425924869231237
        puts
    end
    def rigtReimannSumMethodTest
        y = Num4InteLib.rigtReimannSumMethod(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.140592486923123
        puts
    end
    def trapezioidalRuleTest
        y = Num4InteLib.trapezioidalRule(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.141592486923125
        puts
    end
    def simpsonRuleTest
        y = Num4InteLib.simpsonRule(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.1417591952148007
        puts
    end
end
tst = Num4InteTest.new
tst.leftReimannSumMethodTest()
tst.rigtReimannSumMethodTest()
tst.trapezioidalRuleTest()
tst.simpsonRuleTest()

