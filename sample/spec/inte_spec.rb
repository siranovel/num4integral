require 'spec_helper'
require 'num4inte'

RSpec.describe Num4InteLib do
    before do
        @h = 0.001
        @pi = Math::PI
        @func = Proc.new{|x|
            next 4 / (1 + x * x)
        }
    end
    # 左リーマン和法テスト
    it '#leftReimannSumMethod' do
        expect(
            Num4InteLib.leftReimannSumMethod(0, 1, @h, @func)
        ).to my_round(3.1426, 4)
    end
    # 右リーマン和法テスト
    it '#rigtReimannSumMethod' do
        expect(
            Num4InteLib.rigtReimannSumMethod(0, 1, @h, @func)
        ).to my_round(3.1406, 4)
    end
    # ニュートン・コーツ法(1次:台形公式)テスト
    it '#trapezioidalRule' do
        expect(
            Num4InteLib.trapezioidalRule(0, 1, @h, @func)
        ).to my_round(3.1416, 4)
    end
    # ニュートン・コーツ法(2次:シンプソンの公式)テスト
    it '#simpsonRule' do
        expect(
            Num4InteLib.simpsonRule(0, 1, @h, @func)
        ).to my_round(3.1418, 4)
    end
    # ガウス求積法テスト
    context 'gaussLegendre' do
        it '#gaussLegendreRule 1' do
            expect(
                Num4InteLib.gaussLegendreRule(1, 0, 1, @h, @func)
            ).to my_round(3.1416, 4)
        end
        it '#gaussLegendreRule 2' do
            expect(
                Num4InteLib.gaussLegendreRule(2, 0, 1, @h, @func)
            ).to my_round(3.1416, 4)
        end
        it '#gaussLegendreRule 3' do
            expect(
                Num4InteLib.gaussLegendreRule(3, 0, 1, @h, @func)
            ).to my_round(3.1416, 4)
        end
        it '#gaussLegendreRule 4' do
            expect(
                Num4InteLib.gaussLegendreRule(4, 0, 1, @h, @func)
            ).to my_round(3.1416, 4)
        end
        it '#gaussLegendreRule 5' do
            expect(
                Num4InteLib.gaussLegendreRule(5, 0, 1, @h, @func)
            ).to my_round(3.1416, 4)
        end
    end
end

