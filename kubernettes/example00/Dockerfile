FROM node:alpine
WORKDIR /app
COPY src/package.json .
RUN npm i
COPY src .
EXPOSE 8080
CMD npm start