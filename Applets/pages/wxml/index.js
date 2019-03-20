// pages/wxml/index.js
var js = require('./a.js')

Page({

  /**
   * 页面的初始数据
   */
  data: {
    time:(new Date()).toString(),
    a:1,
    b:2,
    c:3,
    name:"World",
    array:[{
      message:"foo",
    },{
      message:"bar"
    },{
      message:"ok"
    }],
    color:"black",
    font:"45rpx"
  },

  item: {
    time: "2018-11-11"
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    js.myfunc()
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }


})