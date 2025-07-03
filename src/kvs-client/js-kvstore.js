

const net = require('net');

const client = net.createConnection({ port: 2000, host: '192.168.31.43'}, () => {
  console.log('connect kvstore');

  client.write('get Teacher');
});

client.on('data', (data) => {
  console.log(`recv：${data.toString()}`);

  client.end();
});

client.on('error', (err) => {
  console.error('connect failed：', err);
});

client.on('close', () => {
  console.log('close connection');
});



