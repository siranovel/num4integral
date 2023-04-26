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

    #
    # 左リーマン和法
    # @overload leftReimannSumMetod(a, b, h, func)
    #   y = leftReimannSumMetod(a, b, h, func)
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    #
    attach_function :leftReimannSumMetod,
        :CNum4Inte_leftReimannSumMetod, [:double, :double, :double, :f], :double
    #
    # 右リーマン和法
    # @overload rigtReimannSumMetod(a, b, h, func)
    #   y = rigtReimannSumMetod(a, b, h, func)
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    #
    attach_function :rigtReimannSumMetod,
        :CNum4Inte_rigtReimannSumMetod, [:double, :double, :double, :f], :double
    #
    # ニュートン・シンプソン法
    # @overload newtonMethod(a, b, h, func)
    #   y = newtonMethod(a, b, h, func)
    #   @param [double] a aの値
    #   @param [double] b bの値
    #   @param [double] h  刻み幅
    #   @param [callback] func xiに対する傾きを計算する関数
    #   @return [double] [a,b]の間の積分値
    #
    attach_function :newtonMethod,
        :CNum4Inte_newtonMethod, [:double, :double, :double, :f], :double
end

