import express from "express";
import { readFile } from "fs";
import { createServer } from "http";
import { Server } from "socket.io";

let seats = [
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
  [1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
];

const app = express();

app.get("/", (req, res) => {
  readFile("loginPage.html", function (err, data) {
    res.send(data.toString());
  });
});

app.get("/seats", (req, res) => {
  res.send(seats);
});

const server = createServer(app);

server.listen(52273, () => {
  console.log("Server Running at http://127.0.0.1:52273");
});

const io = new Server(server);

io.on("connection", (socket) => {
  socket.on("reserve", (data) => {
    seats[data.y][data.x] = 2;
    io.sockets.emit("reserve", data);
  });
  socket.on("cancel", (data) => {
    seats[data.y][data.x] = 1;
    io.sockets.emit("cancel", data);
  });
});
