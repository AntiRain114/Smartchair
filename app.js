const express = require('express');
const { Client, GatewayIntentBits } = require('discord.js');
const app = express();


const BOT_TOKEN = '*';
const CHANNEL_ID = '*';

const client = new Client({ intents: [GatewayIntentBits.Guilds, GatewayIntentBits.GuildMessages] });

client.login(BOT_TOKEN);

let messages = new Set(); // store

client.on('ready', () => {
    console.log(`Logged in as ${client.user.tag}!`);

    // 5min send
    setInterval(() => {
        if (messages.size > 0) {
            const channel = client.channels.cache.get(CHANNEL_ID);
            if (channel) {
                channel.send(Array.from(messages).join('\n'));
            }
            messages.clear(); // clear
        }
    }, 12000); // 5min
});

app.use(express.json());

app.post('/sendToDiscord', (req, res) => {
    const message = req.body.message;
    //  no none
    if (message && message.trim() !== '') {
        messages.add(message); // noi none confirm
        res.send('Message received');
    } else {
        res.status(400).send('Empty message received, not stored');
    }
});
app.listen(3000, () => {
    console.log('Server is running on port 3000');
});
