#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, (err, res, body) => {
  if (err) return console.error(err);

  const characters = JSON.parse(body).characters;

  const fetchCharacter = (url, callback) => {
    request(url, (err, res, body) => {
      if (err) return callback(err);
      callback(null, JSON.parse(body).name);
    });
  };

  const results = [];
  let completed = 0;

  characters.forEach((url, index) => {
    fetchCharacter(url, (err, name) => {
      if (err) return console.error(err);
      results[index] = name;
      completed++;
      if (completed === characters.length) {
        results.forEach(name => console.log(name));
      }
    });
  });
});
