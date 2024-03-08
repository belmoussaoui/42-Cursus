import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import path from 'path'
import fs from 'fs'

const sslKey = path.resolve(__dirname, '/ssl/key.key')
const sslCert = path.resolve(__dirname, '/ssl/cert.crt')

export default defineConfig({
  plugins: [react()],
  server: {
    host: true,
    port: 4000,
    https: {
      key: fs.readFileSync(sslKey),
      cert: fs.readFileSync(sslCert)
    },
    wss: true,
    origin: 'https://127.0.0.1:4000',
  }
})



