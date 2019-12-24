<?php defined('BASEPATH') or exit('No direct script access allowed');


class graph extends CI_Controller
{
    public function __construct()
    {
        parent::__construct();
        $this->load->model('grafik');
    }
    public function index()
    {
        foreach ($this->grafik->get()->result_array() as $row) {
            $kelembapan[] = (float) $row['kelembapan'];
            $suhu[] = (float) $row['suhu'];
            $waktu[] = date('m/d/Y H:i:s', $row["waktu"]);
        };


        $data['title'] = 'Graph Suhu';
        $this->load->view('templates/head', $data);
        $this->load->view('graph/index');
        $this->load->view('templates/footer', array(
            'data' => $kelembapan,
            'suhu' => $suhu,
            'waktu' => $waktu
        ));
    }
}
