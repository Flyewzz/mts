'use strict';

const when = require('when');

/**
    @return {Promise.<number>}
*/
module.exports = function (requestFactory, processResponseItem) {
    const requests = [];
    let ok = true;
    while (ok) {
        ok = requestFactory.next();
        if (ok) {
            requests.push(ok.then((array) => {
                    let localSum = 0;
                    for (let i = 0; i < array.length; i++) {
                        localSum += processResponseItem(array[i].a);
                    }
                    return localSum;
            }));
        }
    }
    
    return Promise.all(requests).then(localSums => {
        let totalSum = 0;
        localSums.forEach(localSum => {
            totalSum += localSum;
        });
        return totalSum;
    });
};