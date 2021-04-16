FROM tiangolo/node-frontend:10 as build-stage
WORKDIR /app
COPY package*.json ./
RUN npm install
COPY . /app/
RUN npm run build -- --output-path=./dist/out --prod

FROM nginx:1.15
#RUN rm -rf /usr/share/nginx/html/* /etc/nginx/conf.d/default.conf
#COPY nginx.conf /etc/nginx/conf.d/default.conf
#COPY --from=build-stage /usr/share/commander-view/dist /usr/share/nginx/html
#RUN chmod -R o+rX /usr/share/nginx/html/
#RUN systemctl restart nginx
#EXPOSE 80
#ENTRYPOINT [ "nginx", "-g", "daemon off;" ]
EXPOSE 80
COPY --from=build-stage /app/dist/out /usr/share/nginx/html
COPY --from=build-stage /nginx.conf /etc/nginx/conf.d/default.conf
