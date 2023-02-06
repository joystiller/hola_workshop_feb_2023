var osc = require('osc-min'),
    dgram = require('dgram'),
    remote,
    longitude = 21.950683,
    latitude = 65.748682;

var udp = dgram.createSocket('udp4', function (msg, rinfo) {

    // save the remote address
    remote = rinfo.address;

    try {
        console.log(osc.fromBuffer(msg));
    } catch (err) {
        console.log('Could not decode OSC message');
    }

});

getWeather()
setInterval(getWeather, 3600000);


function getWeather() {
    let currentWeather;
    let Wsymb2;
    fetch('https://opendata-download-metfcst.smhi.se/api/category/pmp3g/version/2/geotype/point/lon/' + longitude + '/lat/' + latitude + '/data.json')
        .then(res => res.json())
        .then(data => {

            const currentTime = Date.now() + 3600000; //anpassa tid till +1 UTC
            let timeIndex;

            for (let i = 0; i < data.timeSeries.length; i++) {
                const time = data.timeSeries[i].validTime;
                const timeDate = new Date(time);
                const timeDateUTC = timeDate.getTime();
                if (timeDateUTC > currentTime) {
                    timeIndex = i - 1;
                    break;
                }
            }

            let wsymbIndex;
            for (let i = 0; i < data.timeSeries[timeIndex].parameters.length; i++) {
                if (data.timeSeries[timeIndex].parameters[i].name == 'Wsymb2') {
                    wsymbIndex = i;
                    break;
                }
            }

            Wsymb2 = data.timeSeries[timeIndex].parameters[wsymbIndex].values;

            //convert array to int
            Wsymb2 = parseInt(Wsymb2);

            if (Wsymb2 == 1) {
                currentWeather = 'Klar himmel';
            } else if (Wsymb2 == 2) {
                currentWeather = 'Nästan klar himmel';
            } else if (Wsymb2 == 3) {
                currentWeather = 'Varierande molnighet';
            } else if (Wsymb2 == 4) {
                currentWeather = 'Halvklar himmel';
            } else if (Wsymb2 == 5) {
                currentWeather = 'Molnig himmel';
            } else if (Wsymb2 == 6) {
                currentWeather = 'Mulet';
            } else if (Wsymb2 == 7) {
                currentWeather = 'Dimma';
            } else if (Wsymb2 == 8) {
                currentWeather = 'Lätta regnskurar';
            } else if (Wsymb2 == 9) {
                currentWeather = 'Måttliga regnskurar';
            } else if (Wsymb2 == 10) {
                currentWeather = 'Kraftiga regnskurar';
            } else if (Wsymb2 == 11) {
                currentWeather = 'Åskskurar';
            } else if (Wsymb2 == 12) {
                currentWeather = 'Lätta snöbyar';
            } else if (Wsymb2 == 13) {
                currentWeather = 'Måttliga snöbyar';
            } else if (Wsymb2 == 14) {
                currentWeather = 'Kraftiga snöbyar';
            } else if (Wsymb2 == 15) {
                currentWeather = 'Åska';
            } else if (Wsymb2 == 16) {
                currentWeather = 'Lätta regnskurar och snöblandat';
            } else if (Wsymb2 == 17) {
                currentWeather = 'Måttliga regnskurar och snöblandat';
            } else if (Wsymb2 == 18) {
                currentWeather = 'Kraftiga regnskurar och snöblandat';
            } else if (Wsymb2 == 19) {
                currentWeather = 'Lätta snöbyar';
            } else if (Wsymb2 == 20) {
                currentWeather = 'Måttliga snöbyar';
            } else if (Wsymb2 == 21) {
                currentWeather = 'Kraftiga snöbyar';
            } else if (Wsymb2 == 22) {
                currentWeather = 'Regn';
            } else if (Wsymb2 == 23) {
                currentWeather = 'Snöblandat regn';
            } else if (Wsymb2 == 24) {
                currentWeather = 'Snö';
            } else if (Wsymb2 == 25) {
                currentWeather = 'Lätta regnskurar';
            } else if (Wsymb2 == 26) {
                currentWeather = 'Måttliga regnskurar';
            } else if (Wsymb2 == 27) {
                currentWeather = 'Kraftiga regnskurar';
            }

        })
        .then(() => {
            var osc_msg = osc.toBuffer({
                oscType: 'message',
                address: '/weather',
                args: [{
                    type: 'string',
                    value: currentWeather
                }]
            });
            udp.send(osc_msg, 0, osc_msg.length, 9994, remote);

            var osc_msg2 = osc.toBuffer({
                oscType: 'message',
                address: '/weather_number',
                args: [{
                    type: 'integer',
                    value: Wsymb2
                }]
            });
            udp.send(osc_msg2, 0, osc_msg2.length, 9994, remote);
        })
}

//udp.bind(9994);