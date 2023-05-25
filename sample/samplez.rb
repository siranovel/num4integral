require 'num4inte'

class Num4InteTest
    def initialize
        @h = 0.001
        @pi = Math::PI
        @func = Proc.new{|x|
            next 4 / (1 + x * x)
        }
    end
    #
    # 左リーマン和法テスト
    def leftReimannSumMethodTest
        y = Num4InteLib.leftReimannSumMethod(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.1425924869231237
        puts
    end
    #
    # 右リーマン和法テスト
    def rigtReimannSumMethodTest
        y = Num4InteLib.rigtReimannSumMethod(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.140592486923123
        puts
    end
    #
    # ニュートン・コーツ法(1次:台形公式)テスト
    def trapezioidalRuleTest
        y = Num4InteLib.trapezioidalRule(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.141592486923125
        puts
    end
    #
    # ニュートン・コーツ法(2次:シンプソンの公式)テスト
    def simpsonRuleTest
        y = Num4InteLib.simpsonRule(0, 1, @h, @func)
        print "PI:", @pi
        print " "
        print y                        # 3.1417591952148007
        puts
    end
    #
    # ガウス求積法テスト
    #   n=1 y = 3.1415927369231316
    #   n=2 y = 3.1415926535898757
    #   n=3 y = 3.1415942243860275
    #   n=4 y = 3.141592653589819
    #   n=5 y = 3.141594224386136
    def gaussLegendreRuleTest(n)
        y = Num4InteLib.gaussLegendreRule(n, 0, 1, @h, @func)
        print "n=", n
        print " "
        print "PI:", @pi
        print " "
        print y                        
        puts
    end
end
tst = Num4InteTest.new
tst.leftReimannSumMethodTest()
tst.rigtReimannSumMethodTest()
tst.trapezioidalRuleTest()
tst.simpsonRuleTest()
1.step(5) {|n|
    tst.gaussLegendreRuleTest(n)
}

