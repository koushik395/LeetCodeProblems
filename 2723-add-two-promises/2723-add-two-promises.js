/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    var num1 = await promise1
    var num2 = await promise2
    var sum = num1+num2
    return new Promise(resolve => setTimeout(() => resolve(sum), 20))
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */