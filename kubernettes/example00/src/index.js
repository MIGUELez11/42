const { response } = require("express");
const express = require("express");
const fs = require('fs')

const PORT = 8080;
const app = express();

app.use(express.static(__dirname + "/public"));

app.get("/crash", (req, res) => {
    res.send("Crashing...");
    console.log("server crashed");
    const stream = fs.createReadStream('does-not-exist.txt')
})

app.listen(PORT, () => console.log("Listening on", PORT));