const fs = require('fs')
const m2o = process.binding('m2o')

console.log(m2o.vehicle_position_get(123, 123))
console.log(fs.exists('index.js'))
console.log(process.version)

function foobar(a) {
    setTimeout(() => console.log('async test 1'), 1000)
    setTimeout(() => console.log('async test 2'), 6000)
    setTimeout(() => console.log('async test 3'), 500)
    return a * 5
}

console.log(foobar(15))
