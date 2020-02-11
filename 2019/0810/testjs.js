function Test(props) {
  this.name = props
  this.isWindow1 = () => {
    console.log(this)
  }
}

Test.prototype.sayName = () => {
  console.log(this === global)
}.bind(this)

Test.prototype.sayHi = function () {
  console.log(this)
}

function testGlobal() {
  console.log(this === global)
  console.log(this)
}

const testGlobalTwo = () => {
  console.log(this === global)
  console.log(this)
}

const testThree = () => {
  // testGlobal()
  testGlobalTwo()
}

// testGlobal()
// testGlobalTwo()
// testThree({ foo: 'bar' })
const me = new Test('hi')
me.sayName()
me.sayHi()