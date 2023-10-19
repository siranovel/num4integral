require 'ffi'
require 'ffi-compiler/loader'

#
# 数値計算による数値積分の解法するライブラリ
#
module Num4InteLib
    extend FFI::Library

    ffi_lib FFI::Compiler::Loader.find('num4inte') 
    # @overload f(xi)
    #   dy = f(xi)
    #   @yield [x] dy = f(x)
    #   @yieldparam [double] xi xiの値
    #   @return [double] xiに対するyの値
    callback   :f, [:double], :double

    # 左リーマン和法
    #
    # @overload leftReimannSumMethod(a, b, h, func)
    #   y = leftReimannSumMethod(a, b, h, func)
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    # @example
    #    h = 0.001
    #    func = Proc.new{|x|
    #        next 4 / (1 + x * x)
    #    }
    #    y = Num4InteLib.leftReimannSumMethod(0, 1, h, func)
    #
    attach_function :leftReimannSumMethod,
        :CNum4Inte_reimann_leftReimannSumMethod, [:double, :double, :double, :f], :double
    # 右リーマン和法
    #
    # @overload rigtReimannSumMethod(a, b, h, func)
    #   y = rigtReimannSumMethod(a, b, h, func)
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    # @example
    #    h = 0.001
    #    func = Proc.new{|x|
    #        next 4 / (1 + x * x)
    #    }
    #    y = Num4InteLib.rigtReimannSumMethod(0, 1, h, func)
    #
    attach_function :rigtReimannSumMethod,
        :CNum4Inte_reimann_rigtReimannSumMethod, [:double, :double, :double, :f], :double
    # ニュートン・コーツ法(1次:台形公式)
    #
    # @overload trapezioidalRule(a, b, h, func)
    #   y = trapezioidalRule(a, b, h, func)
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    # @example
    #    h = 0.001
    #    func = Proc.new{|x|
    #        next 4 / (1 + x * x)
    #    }
    #    y = Num4InteLib.trapezioidalRule(0, 1, h, func)
    #
    attach_function :trapezioidalRule,
        :CNum4Inte_rewton_trapezioidalRule, [:double, :double, :double, :f], :double
    # ニュートン・コーツ法(2次:シンプソンの公式)
    #
    # @overload simpsonRule(a, b, h, func)
    #   y = simpsonRule(a, b, h, func)
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    # @example
    #    h = 0.001
    #    func = Proc.new{|x|
    #        next 4 / (1 + x * x)
    #    }
    #    y = Num4InteLib.simpsonRule(0, 1, h, func)
    #
    attach_function :simpsonRule,
        :CNum4Inte_rewton_simpsonRule, [:double, :double, :double, :f], :double
    # ガウス求積法
    #
    # @overload gaussLegendreRule(n, a, b, h, func)
    #   y = gaussLegendreRule(n, a, b, h, func)
    #   @param [int]    n 分割数
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    # @example
    #    h = 0.001
    #    func = Proc.new{|x|
    #        next 4 / (1 + x * x)
    #    }
    #    y = Num4InteLib.gaussLegendreRule(3, 0, 1, h, func)
    #
    attach_function :gaussLegendreRule,
        :CNum4Inte_gauss_gaussLegendreRule, [:int, :double, :double, :double, :f], :double
end

